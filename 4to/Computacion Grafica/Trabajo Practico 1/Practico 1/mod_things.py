#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  mod_things.py
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

MARKER_RADIUS = 4
MARKER_STROKE_RGBA = 0xffff00ff
MARKER_FILL_RGBA = 0xffff0080

import gi
gi.require_version('Gtk', '3.0')
gi.require_version('GooCanvas', '2.0')
from gi.repository import Gtk, GooCanvas

from mod_misc import Vec
import pdb

class Marker:
    def __init__(self, layer, loc, callback = None):
        self.location = loc

        self.mrk = GooCanvas.CanvasEllipse(
                    parent = layer,
                    center_x = self.location.x,
                    center_y = self.location.y,
                    radius_x = MARKER_RADIUS,
                    radius_y = MARKER_RADIUS,
                    fill_color_rgba = MARKER_FILL_RGBA,
                    stroke_color_rgba = MARKER_STROKE_RGBA,
                    line_width = 2)

        self.dragging = False
        self.callback = callback
        self.mrk.connect('button-press-event', self.on_button_pressed)
        self.mrk.connect('button-release-event', self.on_button_released)
        self.mrk.connect('motion-notify-event', self.on_motion_notify)


    def move_to(self, new_location):
        self.mrk.set_property('center_x', new_location.x)
        self.mrk.set_property('center_y', new_location.y)


    def on_button_pressed(self, mrk, tgt, event):
        self.dragging = True
        return True


    def on_button_released(self, mrk, tgt, event):
        self.dragging = False
        self.location = Vec(event.x, event.y, 0)
        return True


    def on_motion_notify(self, mrk, tgt, event):
        if not self.dragging:
            return

        new_loc = Vec(event.x, event.y, 0)
        self.move_to(new_loc)
        if self.callback:
            self.callback(new_loc)

        return True


    def set_callback(self, callback):
        self.callback = callback



class Thing:
    def __init__(self, marker_layer, x, y = 0, z = 0):
        self.marker_layer = marker_layer

        if isinstance(x, Vec):
            self.origin = x

        else:
            self.origin = Vec(x, y, z)


    def set_origin_marker(self, handler):
        self.origin_marker = Marker(self.marker_layer, self.origin, handler)



class Cube(Thing):
    """ Implementa un cubo
        Definido por un vértice de origen, el ancho y el alto
    """
    def __init__(self, layer,
                       width,               # Ancho
                       height,              # Alto
                       depth,               # Profundidad
                       x, y = 0, z = 0):    # Origen
        super().__init__(layer, x, y, z)

        self.size = Vec(width, height, depth)

        # Orden de creación es importante!
        # Primero la figura
        self.front = self.create_drawing(layer)

        # Luego los marcadores
        self.set_origin_marker(self.on_move_thing)
        self.marker2 = Marker(layer, self.origin + self.size, self.on_resize_thing)


    def create_points(self, p1, p2):
        points = GooCanvas.CanvasPoints.new(4)
        points.set_point(0, p1.x, p1.y)
        points.set_point(1, p2.x, p1.y)
        points.set_point(2, p2.x, p2.y)
        points.set_point(3, p1.x, p2.y)
        return points


    def create_drawing(self, layer):
        """ Creación del dibujo en sí
        """
        return GooCanvas.CanvasPolyline(
                    parent = layer,
                    points = self.create_points(self.origin,
                                                self.origin + self.size),
                    close_path = True,
                    stroke_color = 'Red',
                    line_width = 2,
                    fill_color = None)


    def on_resize_thing(self, size_marker):
        """ Si el marker para redimensionar cambia de posición, este método
            se llamará para aplicar los cambios
        """
        self.front.set_property('points',
                    self.create_points(self.origin, size_marker))
        self.size = size_marker - self.origin


    def on_move_thing(self, new_pos):
        """ El callback del marcador de origen llama cuando hay cambios
        """
        self.origin = new_pos
        self.front.set_property(
                    'points',
                    self.create_points(self.origin, self.origin + self.size))
        self.origin_marker.move_to(new_pos)
        self.marker2.move_to(new_pos + self.size)


    def __str__(self):
        return ("cube: origin: {}\n"
                "      size  : {}".format(self.origin, self.size))


def test_cube():
    cv = GooCanvas.Canvas()
    cvr = cv.get_root_item()

    cube = Cube(cvr, 40, 50, 70, Vec(10, 20, 30))
    print(cube)
    cube = Cube(cvr, 40, 50, 70, 10, 20, 30)
    print(cube)


class MainWindow(Gtk.Window):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.connect("destroy", lambda x: Gtk.main_quit())
        self.set_size_request(400, 300)

        self.show_all()

    def run(self):
        Gtk.main()


def main(args):
    test_cube()
    return 0

    mainwdw = MainWindow()
    mainwdw.run()

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
