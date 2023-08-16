#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  demo_canvas.py
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


import gi
gi.require_version('Gtk', '3.0')
gi.require_version('GooCanvas', '2.0')
from gi.repository import Gtk, GooCanvas


MARKER_FILL_RGBA = 0xffff0080
BOX_FILL_RGBA = 0xffffffff


class Marker:
    def __init__(self, layer, x, y):
        mark = GooCanvas.CanvasEllipse(
                    parent = layer,
                    center_x = x, center_y = y,
                    radius_x = 10, radius_y = 10,
                    fill_color_rgba = MARKER_FILL_RGBA)

        mark.connect('button_press_event', self.on_button_pressed)


    def on_button_pressed(self, src, tgt, event):
        print('marker pressed', event.x, event.y)
        return True


class MainWindow(Gtk.Window):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.connect("destroy", lambda x: Gtk.main_quit())
        self.set_default_size(400, 300)

        canvas = GooCanvas.Canvas(
                    automatic_bounds = False,
                    bounds_from_origin = False,
                    bounds_padding = 20)
        canvas.set_bounds(-1000, -1000, 1000, 1000)
        root = canvas.get_root_item()

        root.connect('button_press_event', self.on_root_button_press)
        root.connect('button_release_event', self.on_root_button_release)

        box = self.create_box(root, 0, 0, 100, 150)

        markers = GooCanvas.CanvasGroup(
                    parent = root)
        marker = Marker(markers, 0, 0)

        scroller = Gtk.ScrolledWindow()
        scroller.add(canvas)

        self.add(scroller)
        self.show_all()

    def create_marker_layer(self, parent):
        return

    def create_box(self, parent, x, y, w, h):
        return GooCanvas.CanvasRect(
                    parent = parent,
                    x = x, y = y,
                    width = w, height = h,
                    fill_color_rgba = BOX_FILL_RGBA)

    def on_root_button_press(self, src, tgt, event):
        print('root', event.x, event.y)

    def on_root_button_release(self, src, tgt, event):
        print('root release', event.x, event.y)


    def run(self):
        Gtk.main()


def main(args):
    mainwdw = MainWindow()
    mainwdw.run()

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
