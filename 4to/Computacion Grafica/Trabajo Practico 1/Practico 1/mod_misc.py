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


class RGB:
    colors = {
        'Negro':    (0.0, 0.0, 0.0),
        'Blanco':   (1.0, 1.0, 1.0),
        'Rojo':     (1.0, 0.0, 0.0),
        'Verde':    (0.0, 1.0, 0.0),
        'Azul':     (0.0, 0.0, 1.0),
        'Amarillo': (1.0, 1.0, 0.0)}


    def __init__(self, r = 0.0, g = 0.0, b = 0.0):
        if type(r) is float:
            self.r = r
            self.g = g
            self.b = b

        elif type(r) is str:
            if r[0] == '#':                 # '#1234ab'
                self.r = int(r[1:3], 16)/255
                self.g = int(r[3:5], 16)/255
                self.b = int(r[5:7], 16)/255

            elif r in RGB.colors:
                self.r, self.g, self.b = RGB.colors[r]
            else:
                print('Valor invalido para el color')
                exit(1)

        elif type(r) is RGB:
            self.r, self.g, self.b = r.r, r.g, r.b

        else:
            print('Valor invalido para el color')
            exit(1)


    def __str__(self):
        return 'rgb: r={:.06f} g={:.06f} b={:.06f}'.format(self.r, self.g, self.b)


    def __add__(self, op2):
        self.r += op2.r
        self.g += op2.g
        self.b += op2.b
        return self.clip_colors()


    def clip_colors(self):
        self.r = min(self.r, 1)
        self.g = min(self.g, 1)
        self.b = min(self.b, 1)
        return self


class Vec:
    def __init__(self, x = 0, y = 0, z = 0):
        if isinstance(x, Vec):
            self.x = x.x; self.y = x.y; self.z = x.z
        else:
            self.x, self.y, self.z = x, y, z


    def __str__(self):
        return "vec: x:{:.6g}, y:{:.6g}, z:{:.6g}".format(
                self.x, self.y, self.z)


    def __add__(self, v2):
        return Vec(self.x + v2.x, self.y + v2.y, self.z + v2.z)


    def __sub__(self, v2):
        return Vec(self.x - v2.x, self.y - v2.y, self.z - v2.z)



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


def test_vec():
    v1 = Vec(1, 2, 3)
    print(v1)
    v2 = Vec(0.1, 0.2, 0.3)
    print(v2)
    print('Suma: ', v1 + v2)
    print('Resta: ', v1 - v2)


def main(args):
    # ~test_rgb()
    # ~test_zoom()
    test_vec()
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
