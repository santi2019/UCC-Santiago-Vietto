#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  povparser.py
#
#  Copyright 2022 Unknown <root@hp425>
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

from pyparsing import (Keyword, OneOrMore, Optional, oneOf, Word,
    nums, alphas, alphanums, printables, ZeroOrMore, Combine)

POVFILE = "parser_box.pov"

def parser(which = "scene"):
    integer = Word(nums)
    sign = oneOf("+ -")
    bool = oneOf("on off")
    

    uns_float = (integer + Optional("." + integer) +
                Optional(oneOf("e E") + Optional(sign) + integer))
    signed_float = Combine(Optional(sign) + uns_float)
    signed_float = signed_float.set_parse_action(lambda toks: float(toks[0]))
    vector = ("<" + signed_float + ","
                  + signed_float + ","
                  + signed_float + ">")
    vector2d = ("<" + signed_float + ","
                    + signed_float + ">")


    color = Optional("color") + (oneOf("Yellow White Blue Red") | (Keyword("rgb") + vector))

    # Patterns
    color_pattern = oneOf("checker brick hexagon") + OneOrMore(color + Optional(","))

    # Object Modifiers
    om_pigment = Keyword("pigment") + "{" + (color_pattern | color) + "}"
    om_rotate = Keyword("rotate") + vector 
    om_texture = Keyword("texture") + "{" + om_pigment + "}"
    om_hollow = Keyword("hollow") + bool
    om_noshadow = Keyword("no_shadow")

    object_modifier = om_pigment | om_texture | om_hollow | om_noshadow | om_rotate

    # Camera items
    camera_loc = Keyword("location") + vector
    camera_lookat = Keyword("look_at") + vector
    camera_angle = Keyword("angle") + signed_float

    camera_items = (camera_loc + camera_lookat +
        Optional(camera_angle))

    # Things
    box = (Keyword("box") + "{" + vector + "," + vector +
        ZeroOrMore(object_modifier) + "}")
    sphere = (Keyword("sphere") + "{" + vector + "," + signed_float + 
        ZeroOrMore(object_modifier) + "}")
    triangle = (Keyword("triangle") + "{" + vector + "," + vector + "," + vector +
        ZeroOrMore(object_modifier) + "}")
    cone = (Keyword("cone") + "{" + vector + "," + signed_float + 
        vector + "," + signed_float + Optional("open") +
        ZeroOrMore(object_modifier) + "}")
    cylinder = (Keyword("cylinder") + "{" + vector + "," + vector + 
        "," + signed_float + Optional("open") +
        ZeroOrMore(object_modifier) + "}")
    torus = (Keyword("torus") + "{" + signed_float + "," + signed_float +
        ZeroOrMore(object_modifier) + "}")
    polygon = (Keyword("polygon") + "{" + signed_float + "," +
            OneOrMore(vector2d + Optional(",")) + ZeroOrMore(object_modifier) + "}")

    thing = sphere | box | triangle | cone | cylinder | polygon | torus

    camera = Keyword("camera") + "{" + camera_items + "}"
    light = Keyword("light_source") + "{" + vector + "," + color + "}"
    library = Keyword("#include") + '"' + Word(printables, exclude_chars='"') + '"'

    scene = ZeroOrMore(library) + camera + ZeroOrMore(thing | light)
    return eval(which)


def main(args):
    with open(POVFILE, 'r') as povfile:
        pov = povfile.read()

    pp = parser("scene")
    print(pp.parse_string(pov))
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
