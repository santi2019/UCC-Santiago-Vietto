#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  parser.py
#
#  Copyright 2021 John Coppens <john@jcoppens.com>
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#
#

import pyparsing as pp
# ~from pyparsing.diagram import to_railroad, railroad_to_html
from pathlib import Path
from demo_misc import RGB, Vec3
from demo_things import Sphere, Box

import pdb


'''
     ____
    / ___|  ___ ___ _ __   ___
    \___ \ / __/ _ \ '_ \ / _ \
     ___) | (_|  __/ | | |  __/
    |____/ \___\___|_| |_|\___|

'''


#En la siguiente configuracion, al ejecutar el archivo, se va a verificar
#que todas las palbras o la estructura del archivo pov esten correctos de 
#acuerdo a la siguiente estructura, sean una camera, si es un cylinder, 
#si estan bien escritos, etc.
#
#Una Scene es el todo del archivo pov, es decir, la camara, la figura y la luz.
class Scene:
    def __init__(self):
        self.parser = self.make_parser()

    def make_parser(self, which = "parser"):
        def color_lookup(tokens):
            # ~ print(tokens, RGB.colors[tokens[0]])
            return RGB.colors[tokens[0]]

        # Constantes
        curly_open = pp.Literal("{")
        curly_close = pp.Literal("}")
        comma = pp.Literal(",")

        # Elementos basicos
        unsigned = pp.Word(pp.nums)
        nfloat = pp.Combine(
                    unsigned +
                    pp.Optional(pp.Literal(".") + unsigned))
        nfloat = nfloat.set_parse_action(lambda tokn: float(tokn[0]))

        sfloat = pp.Combine(
                    pp.Optional(pp.oneOf("+ -")) + nfloat)
        sfloat = sfloat.set_parse_action(lambda tokn: float(tokn[0]))
        string = pp.Word(pp.alphas, pp.alphanums)

        # Elementos compuestos
        vector = pp.Group(
                    pp.Literal("<").suppress() + sfloat +
                    pp.Literal(",").suppress() + sfloat +
                    pp.Literal(",").suppress() + sfloat +
                    pp.Literal(">").suppress()
                ).set_parse_action(lambda toks: Vec3(toks[0][0],
                                                     toks[0][1],
                                                     toks[0][2]))

        color_rgb = pp.Group(
                    # ~ pp.Literal("rgb") +
                    pp.Literal("<").suppress() + sfloat +
                    pp.Literal(",").suppress() + sfloat +
                    pp.Literal(",").suppress() + sfloat +
                    pp.Literal(">").suppress()
                ).set_parse_action(lambda toks: RGB(toks[0][0],
                                                    toks[0][1],
                                                    toks[0][2]))

        color_name = pp.oneOf(list(RGB.colors), as_keyword = True)
        color_name.set_parse_action(color_lookup)
        color = pp.Group(pp.Literal("color")
                    + ((pp.Literal('rgb').suppress() + color_rgb) ^ color_name)
                ).set_results_name('color')

        pigment = pp.Group(
                    pp.Literal("pigment") + curly_open.suppress() +
                    color +
                    curly_close.suppress()).set_results_name('pigment')

        # Directivas para POV-ray
        directive = pp.oneOf("#include") + pp.SkipTo(pp.LineEnd())

        # Elementos de la escena
        camera = pp.Group(
                    pp.Literal("camera") + curly_open.suppress()
                    + pp.Group("location"
                        + vector).set_results_name('location')
                    + pp.Group("look_at"
                        + vector).set_results_name('look_at')
                    + pp.Group(pp.Literal("angle")
                        + nfloat).set_results_name('angle')
                    + pp.Optional(pp.Group(pp.Literal("up")
                        + vector))
                    + curly_close.suppress()
                ).set_results_name('camera')

        cylinder = pp.Group(
                    pp.Literal("cylinder")
                    + curly_open.suppress()
                    + vector + pp.Literal(",").suppress()
                    + vector + pp.Literal(",").suppress()
                    + nfloat + pigment
                    + curly_close.suppress()
                ).set_results_name('cylinder')

        sphere = pp.Group(
                    pp.Literal("sphere")
                    + curly_open.suppress()
                    + vector.set_results_name('location')
                    + comma.suppress()
                    + nfloat.set_results_name('radius')
                    + pigment
                    + curly_close.suppress()
                ).set_results_name('sphere')
        
        box = pp.Group(
                    pp.Literal("box")
                    + curly_open.suppress()
                    + vector.set_results_name('lowleft')
                    + comma.suppress()
                    + vector.set_results_name('upright')
                    + pigment
                    + curly_close.suppress()
                ).set_results_name('box')

        light_source = pp.Group(
                    pp.Literal("light_source")
                    + curly_open.suppress()
                    + vector.set_results_name('location')
                    + comma.suppress()
                    + color.set_results_name('color')
                    + curly_close.suppress()
                ).set_results_name('light_source')

        parser = pp.OneOrMore(camera | sphere | cylinder | box | light_source |
                    directive
                ).set_results_name('scene')
        return eval(which)


    #Luego a partir de aca va a ir a parser.parseString.
    def parse_string(self, text):
        return self.parser.parseString(text)


    #Este va a arbir el archivo, lee su contenido, y luego va a parse_string.
    def parse_file(self, povfile):
        with open(povfile) as povf:
            text = povf.read()

        return self.parse_string(text)


    def create_diagram(self, fname):
        self.parser.create_diagram(fname, vertical = 10)


    def make_catalog(self, parsed):
        lights = []
        things = []
        cameras = []
        for el in parsed:
            if isinstance(el, pp.ParseResults):
                if el[0] == 'sphere':
                    things.append(('sphere',
                        Sphere(el.as_dict()['location'],
                               el.as_dict()['radius'],
                               el.as_dict()['pigment']['color'][1])))
                elif el[0] == 'box':
                    things.append(('box',
                        Box(el.as_dict()['lowleft'],
                               el.as_dict()['upright'],
                               el.as_dict()['pigment']['color'][1])))
                elif el[0] == 'light_source':
                    lights.append(el)
                elif el[0] == 'camera':
                    cameras.append(el)
                else:
                    things.append(el)

        return cameras, lights, things

'''
     _            _
    | |_ ___  ___| |_ ___
    | __/ _ \/ __| __/ __|
    | ||  __/\__ \ |_\__ \
     \__\___||___/\__|___/

'''

def test_sphere():
    scene = Scene()
    parser = scene.make_parser('sphere')
    parsed = parser.parseString('sphere { <1, 2, 3>, 4 pigment { color White } }')
    print('parser output:', parsed)
    print('sphere radius:', parsed.sphere.radius)
    print('sphere location:', parsed.sphere.location)
    print('sphere pigment: ', parsed.sphere.pigment)
    print('sphere color: ', parsed.sphere.pigment['color'][1])


def test_camera():
    scene = Scene()
    parser = scene.make_parser('camera')
    parsed = parser.parseString('camera { location <1, 2, 3> '
                                'look_at <0, 0, 0> angle 50}')
    print('parser output:',   parsed)
    # ~ print('camera location:', parsed.camera.location[1])
    # ~ print('camera look_at:',  parsed.camera.look_at[1])
    # ~ print('camera angle:',    parsed.camera.angle[1])


def test_light_source():
    scene = Scene()
    parser = scene.make_parser('light_source')
    parsed = parser.parseString('light_source { <1, 2, 3>, '
                                'color rgb <0.5, 0.5, 0.3> }')
    print('parser output:', parsed)
    print('light_source location:', parsed.light_source.location)
    print('light_source color   :', parsed.light_source.color)


def test_vector():
    scene = Scene()
    parser = scene.make_parser('vector')
    parsed = parser.parse_string('<1.2, 2.3, 3.4>')
    print('parser output:', parsed)


def test_colors():
    scene = Scene()
    parser = scene.make_parser('color')
    for script in ['color Red', 'color rgb <0.1, 0.2, 0.3>']:
        try:
            parsed = parser.parse_string(script)
            print(f'parser  input: {script}\n'
                  f'       output: {parsed}\n'
                  f'               {str(parsed[0][1])}')
        except pp.exceptions.ParseException as m:
            print(m)



def main(args):
    # ~ test_vector()
    test_sphere()
    # ~ test_camera()
    # ~ test_light_source()
    # ~ test_colors()
    return 0

    scene = Scene()

    # Pasar la escena de prueba por el parser e imprimir el resultado
    parsed = scene.parser.parseString(TEST_STRING)
    print(parsed)

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
