#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  gen_scenes.py
#
#  Copyright 2022 John Coppens <john@jcoppens.com>
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

from demo_misc import Vec3
from random import random, seed

def generate_random_cube(nr_balls):
    phy_size = 4.5
    ctr = Vec3(0, 0, 4)

    s = ''
    # Intro
    s += f'#include "colors.inc"\n\n'

    # Cámara
    s += (f'camera {{\n'
          f'    location <0, 0, -5>\n'
          f'    look_at <0, 0, 0>\n'
          f'    angle 40\n'
          f'}}\n\n')

    # Esferas
    seed()
    for nr in range(nr_balls):
        radius = 0.2 * random()
        x0 = (random()-0.5) * phy_size/2
        y0 = (random()-0.5) * phy_size/2
        z0 = (random()-0.5) * phy_size/2
        xcol = random()
        ycol = random()
        zcol = random()

        s += (f'sphere {{\n'
              f'    <{x0:g}, {y0:g}, {z0:g}>, {radius:g}\n'
              f'    pigment {{\n'
              f'        color rgb <{xcol:g}, {ycol:g}, {zcol:g}>\n'
              f'    }}\n'
              f'}}\n\n')

    # Luz o luces
    s += (f'light_source {{\n'
          f'    <-5, -5, -4>,\n'
          f'    color White\n'
          f'}}\n\n')

    print(s)
    return s


def generate_cube(nr_balls, diam):
    phy_size = 2.2
    spacing = phy_size/(nr_balls - 1)
    ctr = Vec3(0, 0, 4)

    s = ''
    # Intro
    s += f'#include "colors.inc"\n\n'

    # Cámara
    s += (f'camera {{\n'
          f'    location <0, 0, -5>\n'
          f'    look_at <0, 0, 0>\n'
          f'    angle 50\n'
          f'}}\n\n')

    # Esferas
    for x in range(nr_balls):
        x0 = ctr.x - phy_size/2 + x * spacing
        xcol = x / (nr_balls - 1)

        for y in range(nr_balls):
            y0 = ctr.y - phy_size/2 + y * spacing
            ycol = y / (nr_balls - 1)

            for z in range(nr_balls):
                z0 = ctr.y - phy_size/2 + z * spacing
                zcol = z / (nr_balls - 1)
                s += (f'sphere {{\n'
                      f'    <{x0:g}, {y0:g}, {z0:g}>, {diam:g}\n'
                      f'    pigment {{\n'
                      f'        color rgb <{xcol:g}, {ycol:g}, {zcol:g}>\n'
                      f'    }}\n'
                      f'}}\n\n')

    # Luz o luces
    s += (f'light_source {{\n'
          f'    <-5, -5, -4>,\n'
          f'    color White\n'
          f'}}\n\n')

    print(s)
    return s


def main(args):
    # ~ s = generate_cube(10, 0.08)
    s = generate_random_cube(200)

    with open('test_gen.pov', 'w') as povf:
        povf.write(s)

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
