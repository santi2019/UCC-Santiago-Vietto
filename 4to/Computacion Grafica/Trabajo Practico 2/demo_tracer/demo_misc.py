#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  ucc1.py
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

from math import cos, sin, radians, sqrt
from PIL import Image

EPSILON = 1e-5   #Definimos el valor de Epsilon

#Definimos la estructura de los colores de tipo RGB.
class RGB:

    def __init__(self, r = 0.0, g = 0.0, b = 0.0):
        if (type(r) is float) or (type(r) is int):
            self.r = r
            self.g = g
            self.b = b

        elif type(r) is str:
            if r[0] == '#':                 # '#1234ab'
                self.r = int(r[1:3], 16)/255
                self.g = int(r[3:5], 16)/255
                self.b = int(r[5:7], 16)/255

            elif r in RGB.colors:
                color = RGB.colors[r]
                self.r, self.g, self.b = color.r, color.g, color.b

            else:
                print(f"Valor invalido para el color '{r}'")
                exit(1)

        elif type(r) is RGB:
            self.r, self.g, self.b = r.r, r.g, r.b

        else:
            print('Valor invalido para el color')
            exit(1)


    def __str__(self):
        return f'rgb: r={self.r:.06f} g={self.g:.06f} b={self.b:.06f}'


    def __add__(self, op2):
        return RGB(self.r + op2.r, self.g + op2.g, self.b + op2.b).clip_colors()


    def __mul__(self, fact):
        return RGB(self.r * fact, self.g * fact, self.b * fact).clip_colors()


    def clip_colors(self):
        self.r = min(self.r, 1)
        self.g = min(self.g, 1)
        self.b = min(self.b, 1)
        return self


    def as_bytes(self):
        """ Retorna una tupla con valores r, g, b en el rango de 0 a 255
        """
        return int(self.r * 255), int(self.g * 255), int(self.b * 255)

#Establece el tipo de color segun el valor del vector.
RGB.colors = {
        'Black'         : RGB(0, 0, 0),
        'White'         : RGB(1, 1, 1),
        'Red'           : RGB(1, 0, 0),
        'Green'         : RGB(0, 1, 0),
        'Blue'          : RGB(0, 0, 1),
        'Orange'        : RGB(1, 0.5, 0),
        'Yellow'        : RGB(1, 1, 0),
        'Cyan'          : RGB(1, 0, 1),
        'Magenta'       : RGB(1, 0, 1),
        'Brown'         : RGB(0.647059, 0.164706, 0.164706),
        'DarkGreen'     : RGB(0.184314, 0.309804, 0.184314),
        'Coral'         : RGB(1.0, 0.498039, 0.0),
        'Gold'          : RGB(0.8, 0.498039, 0.196078),
        'Pink'          : RGB(0.737255, 0.560784, 0.560784),
        'Med_Purple'    : RGB(0.73, 0.16, 0.96),
        'Dark_Purple'   : RGB(0.53, 0.12, 0.47),
        'Violet'        : RGB(0.309804, 0.184314, 0.309804),
        'Gray10'        : RGB(0.1, 0.1, 0.1),
        'Gray20'        : RGB(0.2, 0.2, 0.2),
        'Gray30'        : RGB(0.3, 0.3, 0.3),
        'Gray40'        : RGB(0.4, 0.4, 0.4),
        'Gray50'        : RGB(0.5, 0.5, 0.5),
        'Gray60'        : RGB(0.6, 0.6, 0.6),
        'Gray70'        : RGB(0.7, 0.7, 0.7),
        'Gray80'        : RGB(0.8, 0.8, 0.8),
        'Gray90'        : RGB(0.9, 0.9, 0.9)
    }


#Definimos la estructura de un vector bidimensional.
class Vec2:
    def __init__(self, x = 0, y = 0):
        if isinstance(x, Vec2):
            self.x = x.x; self.y = x.y
        else:
            self.x, self.y = x, y


    def __str__(self):
        return "vec2: x:{:.6g}, y:{:.6g}".format(self.x, self.y)


#Definimos la estructura de un vector tridimensional con sus metodos para sumarlos, restarlos
#valor absoluto, multiplicarlos, normalizarlos (que el vector tenga un modulo igual a 1).
class Vec3:
    def __init__(self, x = 0, y = 0, z = 0):
        if isinstance(x, Vec3):
            self.x = x.x; self.y = x.y; self.z = x.z
        else:
            self.x, self.y, self.z = x, y, z

    def __iter__(self):
        self.current_index = 0
        return self
    def __next__(self):
        if self.current_index == 0:
            self.current_index += 1
            return self.x
        if self.current_index == 1:
            self.current_index += 1
            return self.y
        if self.current_index == 2:
            self.current_index += 1
            return self.z
        raise StopIteration

    def __str__(self):
        return f"vec3: x:{self.x:.6g}, y:{self.y:.6g}, z:{self.z:.6g}"


    def __add__(self, v2):
        return Vec3(self.x + v2.x, self.y + v2.y, self.z + v2.z)


    def __sub__(self, v2):
        return Vec3(self.x - v2.x, self.y - v2.y, self.z - v2.z)


    def __abs__(self):
        return sqrt(self.x * self.x + self.y * self.y + self.z * self.z)


    def __mul__(self, v3):
        if isinstance(v3, Vec3):
            return self.x*v3.x + self.y*v3.y + self.z*v3.z
        else:
            return Vec3(self.x*v3, self.y*v3, self.z*v3)

 
    def normalized(self):
        """ Normaliza los componentes x, y, z
        """
        d = abs(self)
        self.x /= d
        self.y /= d
        self.z /= d
        return self


    #Desde aqui hasta rotate, no usamos estas funciones.
    def from_xy(self, which, x, y):
        if   which == 'XY': self.x, self.y, self.z = x, -y, 0
        elif which == 'ZY': self.x, self.y, self.z = 0, -y, x
        elif which == 'XZ': self.x, self.y, self.z = x, 0, y
        else: raise 'Vec3.from_xy: Cannot do this in the perspective view'

        return self


    def to_xy(self, which):
        if   which == 'XY': return  self.x, -self.y
        elif which == 'ZY': return -self.y,  self.z
        elif which == 'XZ': return  self.x,  self.z

        raise 'Vec3.to_xy: Cannot do this in the perspective view'


    def rotate_x(self, angle):
        """ Ángulos son expresados en grados """
        c = cos(radians(angle))
        s = sin(radians(angle))
        return Vec3(self.x,
                   self.y * c - self.z * s,
                   self.y * s + self.z * c)


    def rotate_y(self, angle):
        """ Ángulos son expresados en grados """
        c = cos(radians(angle))
        s = sin(radians(angle))
        return Vec3(self.x * c + self.z * s,
                   self.y,
                   -self.x * s + self.z * c)


    def rotate_z(self, angle):
        """ Ángulos son expresados en grados """
        c = cos(radians(angle))
        s = sin(radians(angle))
        return Vec3(self.x * c - self.y * s,
                   self.x * s + self.y * c,
                   self.z)


#Aca definimos la estructura del rayo, en donde el mismo va a ser una recta
#que va a tener un origen y una direccion que pasa por un punto
class Ray:
    """ Caracteristicas del rayo:
            - Origen
            - Dirección
    """
    def __init__(self, org, dir):
        self.origin, self.direction = Vec3(org), Vec3(dir)


    def __str__(self):
        return "ray: {}\n     {}".format(self.origin, self.direction)


    def at(self, t):
        """ 'at' devuelve la posición (en el espacio 3D de un punto sobre
            el rayo. 't' es la distancia viajado desde el origen en la
            dirección indicada.
        """
        return self.origin + self.direction * t


#Este no lo usamos.
class Zoom:
    def __init__(self, initial = 0):
        self.actual = initial
        self.steps_per_decade = 6


    def get_zoom(self):
        return 10**(self.actual / self.steps_per_decade)


    def zoom_in(self):
        self.actual = min(20, self.actual + 1)


    def zoom_out(self):
        self.actual = max(-20, self.actual - 1)


#Tenemos la estructura del hit, que va a tener el punto de impacto, la
#normal en el punto y la referencia al objeto.
class Hit:
    """ Objeto contiene los datos necesarios del impacto de un rayo:
            - Punto de impacto (t)
            - La normal en el punto de impacto (normal)
            - Una referencia del objeto (thing) impactado
    """
    def __init__(self, t, normal, thing):
        self.t, self.normal, self.thing = t, normal, thing


    def __str__(self):
        return (f'hit: t: {self.t}, normal: {self.normal}, \n'
                f'     thing: {self.thing}')



class RGB_image:
    def __init__(self, width, height):
        self.w, self.h = width, height
        self.img = Image.new('RGB', (width, height))
        self.pixels = self.img.load()
        self.index = 0


    def add_pixel(self, color):
        """ Add a pixel and increment the index pointer
            Color is in RGB class format
        """
        x, y = self.index % self.w, self.index // self.w
        self.pixels[x, y] = color.as_bytes()
        self.index = (self.index + 1) % (self.w * self.h)


    def show(self):
        self.img.show()


    def save(self, fname):
        self.img.save(fname, 'PNG')



def test_rgb():
    rgb = RGB()
    print(rgb)
    rgb = RGB(.123, .234, .345)
    print(rgb)
    rgb = RGB('Amarillo')
    print(rgb)
    rgb2 = RGB(rgb)
    print(rgb2)
    rgb = RGB('#ffff00')
    print(rgb)
    rgb1 = RGB('Amarillo') + RGB('Rojo')
    print(rgb1)


def test_zoom():
    z = Zoom(-5)
    for i in range(25):
        print(i, z.get_zoom())
        z.zoom_in()


def test_vec3():
    v1 = Vec3(1, 2, 3)
    print(v1)
    v2 = Vec3(0.1, 0.2, 0.3)
    print(v2)
    print('Suma: ', v1 + v2)
    print('Resta: ', v1 - v2)
    v1 = Vec3(1, 1, 1)
    print(v1)
    print('   Rotate 90° around X:', v1.rotate_x(90))
    print('   Rotate 90° around Y:', v1.rotate_y(90))
    print('   Rotate 90° around Z:', v1.rotate_z(90))
    v1 = Vec3(1, 2, 3)
    print(v1)
    print('   Rotate 90° around X:', v1.rotate_x(90))
    print('   Rotate 90° around Y:', v1.rotate_y(90))
    print('   Rotate 90° around Z:', v1.rotate_z(90))

    v = Vec3()
    for which in ['XY', 'ZY', 'XZ']:
        print(which + ':', v.from_xy(which, 1, 2))
        print(which + ':', v.to_xy(which))


def test_vec2():
    v1 = Vec2(1, 2)
    print(v1)
    v2 = Vec2(0.1, 0.2)
    print(v2)
    v3 = Vec2(v1)
    print(v3)


def test_image():
    W = 500; H = 400
    img = RGB_image(W, H)
    for y in range(H):
        for x in range(W):
            # y/H y x/W generan valores de 0 a 1
            img.add_pixel(RGB(y/H, 0, x/W))
    img.show()
    # ~ img.save('rgb_test.png')


def test_hit():
    hit = Hit(1.23, Vec3(11, 22, 33), None)
    print(hit)


def main(args):
    # ~ test_rgb()
    # ~ test_zoom()
    # ~ test_vec3()
    # ~ test_vec2
    # ~ test_image()
    test_hit()
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
