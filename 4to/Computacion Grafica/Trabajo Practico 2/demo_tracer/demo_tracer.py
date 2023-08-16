#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  demo_tracer.py
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

import pylab as plt
from demo_parser import Scene
from demo_misc import RGB, Vec3, Ray, RGB_image, Hit, EPSILON
from demo_things import Light_source, Sphere

import pdb
from math import tan, radians, sqrt

DEMO_SCENE = 'test_mini.pov'
AMBIENT = 0.3
DEMO_SAVE  = True
DEMO_FNAME = 'demo_tracer.png'
WIDTH  = 800
HEIGHT = 600

'''
                                                         _
     _ __ __ _ _   _      __ _  ___ _ __   ___ _ __ __ _| |_ ___  _ __
    | '__/ _` | | | |    / _` |/ _ \ '_ \ / _ \ '__/ _` | __/ _ \| '__|
    | | | (_| | |_| |   | (_| |  __/ | | |  __/ | | (_| | || (_) | |
    |_|  \__,_|\__, |____\__, |\___|_| |_|\___|_|  \__,_|\__\___/|_|
               |___/_____|___/
'''

#Se pasa por parametros un ancho y altura que va a ser de la pantalla que se
#genera al ejecutar el codigo, en donde estas estan previamente definidas arriba
#al principio del archivo, por ende en este caso va a tener que crear 800x600 rayos,
#es decir, uno por cada pixel de la pantalla.
def ray_generator(w, h, loc, angle):
    """ Generador que fabrica los rayos que necesitamos en el rasterizador.
        Cada llamada entrega una instancia nueva del objeto Ray.
    """

    #Aqui se calcula cuanto va a medir cada pixel (el ancho).
    width = abs(loc.z) * 2 * tan(radians(angle)/2)
    pixel = width / w

    #Luego, por cada i (pixel) en 800x600, calcula la posicion de donde empieza, el
    #X y el Y.
    for i in range(w*h):
        x = (i % w)  - (w//2) + 0.5
        y = (i // w) - (h//2) + 0.5
    # Luego, los multiplica por el ancho del pixel para poder cargarlo en la pantalla.
        x *=  pixel
        y *= -pixel
    #Calcula la direccion, que lo hace con la posicion de la camara y el X y el Y,
    #calculados antes.
        direction = Vec3(x - loc.x, y - loc.y, 0 - loc.z)

    #Y por ultimo vamos a generar el rayo en si, que el mismo no es otra cosa que una 
    #recta, que va a estar dada por la ubicacion de la camara donde empieza, y la 
    #direccion que calculamos antes. Entonces, va a ser una recta formada por un vector
    #con una direccion y una posicion.
        yield Ray(loc, direction.normalized())


#Al venir un rayo por ejemplo, toca un objeto y ese es el primer hit, pero si en vez de
#que rebote y nos muestre la imagen, dejamos que el rayo traspase el objeto y toque la
#parte de atras, y ese es el segundo hit. Entonces cuando hagamos la siguiente funcion 
#de hit, nos van a aparecer dos hits, el primero y el segundo que no nos interesa porque
#esta detras, por ende el que nos interesa es el primero porque es el hit mas cercano.
def nearest_hit(ray, things):
    """ De la lista de impactos (hits), seleccionar el mas cercano a la
        cámera. Si la lista original está vacia, retorna None
    """
    #Por cada una de las cosas que hayamos separado antes, vamos a calcular los hits
    #y los vamos a cargar en un arreglo. Por ejemplo, pueden ser dos hits en una caja.
    hits = []
    for thing in things:
        hits += thing[1].intersection(ray)

    #Luego, por cada uno de los hits, vamos a fijar cual es el mas cercano. 
    nearest = None
    for hit in hits:
    #Entonces al primer hit que tengamos, lo vamos a marcar como el mas cercano.
        if nearest == None:
            nearest = hit
    #Y al aparecer otro hit, se va a fijar si el hit nuevo que estamos comparando,
    #tiene un tiempo menor al hit que estamos considerando mas cercano. Entonces,
    #colocamos el primer hit que encuentro como el mas cercano, y luego nos fijamos
    #que el hit nuevo que detectamos tarda menos que el que ya se considero como mas 
    #cercano, en donde si es asi, a este nuevo hit se lo considera como el mas cercano
    #y de lo contrario mantenemos el primer hit.
        else:
            if hit.t < nearest.t:
                nearest = hit
    return nearest
    #Aca no se comparan los hits de rayos diferentes, sino que esto es por cada rayo, es
    #decir, son los hits del mismo rayo.



def trace_rays_text(raygen, sphere):
    """ Trazar la escena, y mostrar al resultado como caracteres.
        Funciona unicamente con luz ambiental (solo con color/sin color)
    """
    s = ''
    for ray in raygen:
        hits = sphere.intersection(ray)
        if len(hits) != 0:
            s += 'MM'
        else:
            s += '  '
    for i in range(0, WIDTH*HEIGHT*2, WIDTH*2):
        print(s[i : i+WIDTH*2])


#Una vez que tenemos todos los rayos generados, la posicion de la camra,
#los objetos o things, y las luces, vamos a entrar a la siguiente funcion.
def trace_rays_graphics(raygen, things, lights):
    """ Trazar la escena, y mostrar al resultado en forma gráfica.
    """
    
    #Lo primero que hacemos es generar una imagen con el alto y el ancho que
    #necesitamos, cuyos valores son los que definimos al principio.
    rgb = RGB_image(WIDTH, HEIGHT)
    
    #Ahora, por cada uno de los rayos que generamos antes...
    for ray in raygen:
        #Calculamos cual es el hit mas cercano del rayo que incide en el objeto.
        #Esta operacion se calcula para cada uno de los rayos.
        hit = nearest_hit(ray, things)

        #Ahora, si tenemos un impacto o hit...
        if hit:
            # ~ pdb.set_trace()
            #   nos fijamos si está iluminado por la fuente de luz
            #   el rayo inicia en la luz hacia la esfera
            hit_thing = hit.thing       #Se fija contra que objeto choco.
            hit_point = ray.at(hit.t)   #Calcula el punto de impacto en el objeto, su coordenada especifica.
            hit_color = hit_thing.color #Se fija el color que posee el objeto.

            #Nosotros arrancamos por la camara, porque la luz va a generar una cantidad enorme de rayos
            #y hay muchos rayos que la luz va a generar, que no vamos a ver porque no van a rebotar
            #contra la camara, entonces arrancamos por la camara y nos fijamos en que puntos nosotros
            #si vemos. Por ende, sabiendo los puntos que si vemos, tenemos que determinar que rayos de
            #luz chocan en ese punto, de esta manera reducimos la cantidad de rayos que tenemos que calcular.
            #
            #Cuando el rayo saliente de la camara inside en el objeto, en un punto especifico, nos fijamos 
            #donde esta la fuente de luz, y para eso generamos otro rayo para ir hasta la fuente de luz, que
            #seria lo inverso a la vida real, en donde los rayos de la luz insiden en el objeto y los rayos se
            #reflejan en los ojos. Entonces calculamos el rayo que va del objeto a la luz.
            #
            #Vemos la posicion de la luz y luego calculamos el nuevo rayo hacia la luz, formado por una recta 
            #que pasa por un punto y tiene una direccion. El punto por el que pasa es la posicion en la luz y 
            #la direccion va a ser el punto de impacto del rayo en el objeto desde la camara menos la posicion de la luz.
            light_loc = lights[0].location  
            light_ray = Ray(light_loc, (hit_point - light_loc).normalized())

            #Controlamos si no hay obstaculos en el camino.
            nearest_light_hit = nearest_hit(light_ray, things)

            #El EPSILON es un numero muy pequeño que se lo considera casi como 0.
            if abs(nearest_light_hit.t - abs(hit_point - light_loc)) > EPSILON:
                #Si hay sombra, lo que hace es pintar el pixel del color de la figura y lo multiplica por la
                #constante AMBIENT (luz ambiente) que esta definida al comienzo del archivo, generando que se 
                #vea un poco mas oscuro.
                rgb.add_pixel(hit_color * AMBIENT)

            #En el caso de que no haya sombra (por que el rayo pega directamente en la figura)...    
            else: #La luz llega a la figura, y calculamos la intensidad de la misma.
                #Lo que hace es calcular el angulo entre la direccion del rayo de la luz y la normal del hit.
                cos_angle = -(light_ray.direction * hit.normal)
                illumination = hit_color * AMBIENT   #Consideramos la iluminacion, que seria el color por la iluminacion ambiente.
                
                #Entonces, si entre la normal del objeto y el rayo de luz es mayor a 0, significa que le esta pegando directamente
                #o con un angulo menor a 90 grados. Por lo tanto, cuanto mas cerca este el angulo a 90º menor va a ser la intensidad
                #de la luz. Entonces, si el coseno del angulo es mayor a 0, la ilumniacion va a ser el color ambiente y le sumamos
                #el color por el coseno del angulo, y al sumarle lo hacemos mas brillante. Y al final pintamos ese pixel por el color 
                #de la iluminacion que calculamos. Con el coseno determinamos que tan fuerte va a ser la iluminacion en donde esta ya
                #tiene en cuenta el color.
                if cos_angle > 0:  
                    illumination = illumination + (hit_color * cos_angle)
                rgb.add_pixel(illumination)

        #Pero, si no hay un impacto, es decir, si el rayo no choco con ningun objeto,
        #pinta ese pixel de negro, representando el vacio.
        else:
            rgb.add_pixel(RGB('Black'))
        
    rgb.show()     #Mostramos la imagen, que la definimos antes con tal ancho y tal alto.
    if DEMO_SAVE:
        rgb.save(DEMO_FNAME)   #Guardamos la imagen.


def plot_rays(raygen):
    """ Rutina para controlar al generador de rayos. Plotea los vectores de
        dirección, utilizando MatPlotLib
    """
    x = []; y = []
    for r in raygen:
        d = r.direction
        x.append(d.x)
        y.append(d.y)

    plt.plot(x, y, '.')
    plt.title('Gráfico de los puntos finales de los rayos')
    plt.axis('equal')
    plt.show()


def export_rays(raygen):
    """ Exporta los 'rayos' del generador, por si quieren utilizarlos
        para otro programa
    """
    x = []; y = []

    with open('ray_export.csv', 'w') as outf:
        for r in raygen:
            d = r.direction
            l = r.origin
            print(("{:.6g},"*6).format(l.x, l.y, l.z, d.x, d.y, d.z),
                file = outf)



#Este es el archivo principal del programa, y empieza por el main.
def main(args):
    #Lo primero que hace es leer la escena del archivo fuente (pov),
    #recordamos que en el archivo pov se definen las figuras.
    scene = Scene()
    #Luego, una vez que tiene el archivo, va a usar el parser para
    #sacar los elementos claves del mismo, mediante parse_file.
    parsed = scene.parse_file(DEMO_SCENE)
    print(parsed)


    #Luego de parsear la scene, va a serparar los elementos claves del archivo
    #pov en las variables camara, luces y en cosas para mayor claridad.
    cameras, lights, things = scene.make_catalog(parsed)

    #En este caso, chequea que si no hay luces va a haber luz ambiente
    #y se va a ver oscuro.
    if len(lights) == 0:
        print('No lights defined. Only ambient light will be used!')

    #Si no hay cosas, va a saltar un error ya que no se puede ver nada
    #si no hay objetos.
    if len(things) == 0:
        print('You can\'t see anything without objects!')
        exit(1)

    #Si no hay camaras, avisa que necesita por lo menos una camara definida.
    if len(cameras) == 0:
        print('At least one camera must be defined.')
        exit(1)


    #Luego va a sacar de la camara, del archivo pov, en que locacion 
    #esta y el angulo, almacenandolas en las siguientes variables:
    camera_loc = cameras[0].location[1] #Vector definido en el pov
    camera_angle = cameras[0].angle[1] #Float definido en el pov

    #Una vez que tenemos definidos todas las cosas anteriores (camaras,
    #luces, etc), lo que vamos a hacer ahora es crear el generador de
    #los rayos, que es el proceso de ray tracing.
    #
    #Se posiciona sobre la camara, tomando su ubicacion y el angulo definido,
    #para saber desde donde tiene que crear los rayos.
    raygen = ray_generator(WIDTH, HEIGHT, camera_loc, camera_angle)


    #La siguiente es la parte mas importante ya que lo que el programa hace aca
    #es fijarse que rayos chocan con un objeto, y que rayos no. Ademas va a fijarse
    #la intensidad de la luz, de que color va a tener que pintar cada objeto, y para eso
    #vamos a necesitar los rayos que generamos (uno por cada pixel), las cosas u objetos
    #que encontramos en el archivo pov (figuras) y la luz.
    #
    # ~ plot_rays(raygen)
    # ~ export_rays(raygen)
    # ~ trace_rays_text(raygen, sphere)
    trace_rays_graphics(raygen, things, lights)

    return 0



if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
