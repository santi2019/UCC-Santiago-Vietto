#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  things.py
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

from demo_misc import RGB, Vec3, Ray, Hit, EPSILON
from math import sqrt
import numpy as np
from itertools import cycle
import pdb

class Cylinder:
    def __init__(self, origin, end = None, radius = None):
        """ Sphere constructor: Si <loc> es una lista (como la producida por el
            parser), utilizar los datos contenidos. Sino considerar <loc> y
            <radius> como los datos.
        """
        if isinstance(origin, dict):
            self.origin, self.end, self.radius = origin['origin'], origin['end'], origin['radius']
        else:
            self.origin, self.end, self.radius = origin, end, radius


    def __str__(self):
           return f'cylinder: origin: {self.origin}, end: {self.end} radius: {self.radius}'

    def divide(self, vec, num):
        vec.x = vec.x / num
        vec.y = vec.y / num
        vec.z = vec.z / num
        return vec


    def intersection(self, ray):
        """ Cálculo de eventuales puntos de impacto del rayo
        """
        r0 = ray.origin
        r1 = ray.direction
        p1 = self.origin
        p2 = self.end
        v = (p2-p1).normalized()
        va = (p1-p2).normalized()
        r = self.radius


        a = (v-(v*va)*va)**2
        b = 2*(v-(v*va)*va)*(p2-((p2-p1)*va)*va)
        c = p2-p1-((p2-p1)*va)**2-r

        d = b**2 - 4*a*c
        if d > 0:                       # Dos raices diferentes
            r1 = (-b - sqrt(d))/2/a
            r2 = (-b + sqrt(d))/2/a
            center = self.origin+self.end
            return [Hit(r1, (ray.at(r1) - self.divide(center,2)).normalized(), self),
                    Hit(r2, (ray.at(r2) - self.divide(center,2)).normalized(), self)]

        elif abs(d) < EPSILON:          # Notar el uso de EPSILON, no 0.0!
            r = -b/2/a
            return [Hit(r, (ray.at(r) - (self.origin+self.end)/2).normalized(), self)]

        else:
            return []


'''
     ____        _
    / ___| _ __ | |__   ___ _ __ ___
    \___ \| '_ \| '_ \ / _ \ '__/ _ \
     ___) | |_) | | | |  __/ | |  __/
    |____/| .__/|_| |_|\___|_|  \___|
          |_|
'''
class Sphere:
    def __init__(self, loc, radius = None, color = RGB.colors['White']):
        """ Sphere constructor: Si <loc> es una lista (como la producida por el
            parser), utilizar los datos contenidos. Sino considerar <loc> y
            <radius> como los datos.
        """
        if isinstance(loc, dict):
            self.loc, self.radius = loc['location'], loc['radius']
            self.color = loc['color']
        else:
            self.loc, self.radius, self.color = loc, radius, color


    def __str__(self):
        return (f'sphere: location {self.loc}, '
                f'radius: {self.radius}, '
                f'color: {self.color}')


    def to_pov(self):
        return (f'sphere {{\n'
                f'    <{self.loc.x:g}, {self.loc.y:g}, {self.loc.z:g}>, '
                f'    {self.radius:g}\n'
                f'    pigment {{\n'
                f'        color {{ rgb<{self.color.r}, '
                                     f'{self.color.g}, '
                                     f'{self.color.b}> }}\n'
                f'    }}\n'
                f'}}\n')


    def intersection(self, ray):
        """ Cálculo de eventuales puntos de impacto del rayo
        """
        a = 1
        b = ray.direction * (ray.origin - self.loc) * 2
        c = abs(ray.origin - self.loc)**2 - self.radius**2

        d = b**2 - 4*a*c
        if d > 0:                       # Dos raices diferentes
            r1 = (-b - sqrt(d))/2/a
            r2 = (-b + sqrt(d))/2/a
            return [Hit(r1, (ray.at(r1) - self.loc).normalized(), self),
                    Hit(r2, (ray.at(r2) - self.loc).normalized(), self)]

        elif abs(d) < EPSILON:          # Notar el uso de EPSILON, no 0.0!
            r = -b/2/a
            return [Hit(r, (ray.at(r) - self.loc).normalized(), self)]

        else:
            return []

class Box:
    def __init__(self, lowleft, upright = None, color = RGB.colors['White']):
        if isinstance(lowleft, dict):
            self.lowleft, self.upright = loc['lowleft'], loc['upright']
            self.color = lowleft['color']
        else:
            self.lowleft, self.upright, self.color = lowleft, upright, color


    def __str__(self):
        return (f'box: 1st corner {self.lowleft}, '
                f'2nd corner: {self.upright}, '
                f'color: {self.color}')


    def to_pov(self):
        return (f'sphere {{\n'
                f'    <{self.loc.x:g}, {self.loc.y:g}, {self.loc.z:g}>, '
                f'    {self.radius:g}\n'
                f'    pigment {{\n'
                f'        color {{ rgb<{self.color.r}, '
                                     f'{self.color.g}, '
                                     f'{self.color.b}> }}\n'
                f'    }}\n'
                f'}}\n')


    def intersection(self, ray):

        #Tenemos las 6 ecuaciones de los planos para determinar la posicion del cubo, es 
        #decir, sus caras visibles, y tambien creamos las normales, para luego calcular 
        #los puntos de impacto del rayo.
        planos1 = [ self.lowleft.x, self.lowleft.y, self.lowleft.z ]
        planos2 = [ self.upright.x, self.upright.y, self.upright.z ]
        normals = [ Vec3(1,0,0), Vec3(0,1,0), Vec3(0,0,1) ]

        #La idea es fijarse basicamente que cada punto donde inside un rayo, estos formen 
        #parte de alguna de las caras del cubo, fijandose en los planos X, Y y Z.
        
        #Definimos las siguientes variables, utilizadas para determinar la orientación del 
        #plano y la ubicación del cubo y de la cámara, y como se encuentran uno respecto al otro.
        #Si tnear > tfar → falla, porque el punto no esta en alguna de las caras del cubo.
        #Si tnear < tfar → Intersección.
        #Ambas se igualan a infinito. 
        tnear = -np.inf    #Este es la distancia de la incidencia mas cercana del rayo de la camara en el cubo.
        tfar = np.inf      #Este es la distancia de la incidencia mas lejana del rayo de la camara en el cubo.

        #La variables rd representa la direccion del rayo (donde termina) de la camara y ro es en 
        #comienza un rayo (origen) de la camara, y las variables t hacen referencia a la distancia.
        for p1, p2, rd, ro, n in zip(planos1, planos2, ray.direction, ray.origin, normals):
            #Si la direccion del rayo es igual a 0, porque el angulo vale 90º, siendo paralelos
            #al eje X, verificamos que si el origen del rayo a su vez no esta entre los planos 1
            #y 2, entonces no hay un hit (punto visible donde el rayo choca la figura).
            if rd == 0:
                if ro < p1 or ro > p2:
                    return []
            #Caso contrario, el rayo no es paralelo al plano. Por ende lo que hacemos es calcular 
            #la distancia de intersección de los planos.
            else:
                t1 = (p1 - ro) / rd
                t2 = (p2 - ro) / rd

            if t1 > t2:
                t1, t2 = t2, t1    #Intercambiamos, desde la intersección t1 con el plano cercano.
            if t1 > tnear:         #Se busca un tnear mas grande y se guarda el hit.
                tnear = t1
                hit1 = Hit(tnear, n.normalized()*-1, self)
            if t2 < tfar:          #Se busca un tfar mas pequeño, y se guarda el hit.
                tfar = t2
                hit2 = Hit(tfar, n.normalized(), self)
            if tnear > tfar:   #En este caso, la caja está perdida.
                return []
            if tfar < 0:       #En este caso, la caja está detrás de la cámara.
                return []

        return [ hit1, hit2 ]   #Se retornan la lista de hits que representan un punto visible.



'''
     _     _       _     _
    | |   (_) __ _| |__ | |_     ___  ___  _   _ _ __ ___ ___
    | |   | |/ _` | '_ \| __|   / __|/ _ \| | | | '__/ __/ _ \
    | |___| | (_| | | | | |_    \__ \ (_) | |_| | | | (_|  __/
    |_____|_|\__, |_| |_|\__|___|___/\___/ \__,_|_|  \___\___|
             |___/         |_____|
'''
class Light_source:
    def __init__(self, loc, color = RGB('White')):
        if isinstance(loc, dict):
            self.location, self.color = loc['location'], loc['color']
        else:
            self.location, self.color = loc, color


    def to_pov(self):
        return (f'light_source {{\n'
                f'    <{self.location.x:g}, {self.location.y:g}, {self.location.z:g}>,'
                f'    color {{rgb<{self.color.r}, '
                                f'{self.color.g}, '
                                f'{self.color.b}> }}\n'
                f'    }}\n'
                f'}}\n')

'''
     _            _
    | |_ ___  ___| |_ ___
    | __/ _ \/ __| __/ __|
    | ||  __/\__ \ |_\__ \
     \__\___||___/\__|___/

'''
def test_sphere():
    # Crear esfera con resultado del parser
    # Simular el resultado del parser:
    a_color = RGB.colors['Yellow']

    lst = {'location': Vec3(1, 2, 3), 'radius': 2.4, 'color': a_color}
    sphere1 = Sphere(lst)
    print('Sphere([Vec3(1, 2, 3), 2.4, a_color]):\n    ', sphere1)

    # Test con parámetros directos
    sphere2 = Sphere(Vec3(1.1, 2.2, 3.3), 4.4, a_color)
    print('Sphere(Vec3(1.1, 2.2, 3.3), 4.4, a_color):\n    ', sphere2)

    # Generar el código para POVray
    print('To POV:')
    print(sphere2.to_pov())

    # Probar intersecciones, impactando 1) de lleno, 2) tangencial, 3) alto
    for h in (0, 4.4, 4.6):
        ray = Ray(Vec3(1, h, 0), Vec3(0, 0, 1))
        print(f'\n{ray}: ')
        print('-'*80 + '\n',
              'Intersection(s):')
        for hit in sphere1.intersection(ray):
            print(hit)



def main(args):
    test_sphere()
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
