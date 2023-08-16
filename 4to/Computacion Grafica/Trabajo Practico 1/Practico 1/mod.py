#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  demo2.py
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


import gi
gi.require_version('Gtk', '3.0')
gi.require_version('GooCanvas', '2.0')
gi.require_version('Gdk', '3.0')
from gi.repository import Gdk, Gtk, GooCanvas

import os.path as osp
from mod_menu import Main_menu
from mod_misc import Zoom, Vec
from mod_things import Cube
import pdb

ICONS_PATH = 'icons'

class Tools(Gtk.Frame):
    def __init__(self):
        super(Tools, self).__init__(
                    label = 'Tools')

        vbox = Gtk.VBox()
        for img_name, hint in (('tool_box.svg', 'Caja'),
                               ('tool_sphere.svg', 'Esfera')):
            btn = Gtk.Button(
                        relief = Gtk.ReliefStyle.NONE)
            btn.set_tooltip_text(hint)
            img = Gtk.Image.new_from_file(osp.join(ICONS_PATH, img_name))
            btn.set_image(img)
            vbox.pack_start(btn, False, False, 0)

        self.add(vbox)


class View(Gtk.Frame):
    def __init__(self, kind):
        super(View, self).__init__(
                    label = kind,
                    label_xalign = 0.04,
                    label_yalign = 0.5,
                    hexpand = True,
                    vexpand = True)

        self.kind = kind
        self.items = []
        self.canvas = GooCanvas.Canvas()
        self.canvas.set_bounds(-1000, -1000, 1000, 1000)

        self.cvroot = self.canvas.get_root_item()

        # Crear 'capas' dedicadas a propositos específicos:
        self.marker_layer = GooCanvas.CanvasGroup(
                    parent = self.cvroot,
                    x = 0, y = 0)

        # E inicializar el zoom
        self.zoom = Zoom()
        self.set_zoom(self.zoom.get_zoom())

        # Definir eventos a procesar
        self.cvroot.connect_after('button_press_event', self.on_button_pressed)
        self.cvroot.connect('scroll_event', self.on_wheel_scroll)

        self.scroller = Gtk.ScrolledWindow(overlay_scrolling = False)
        self.scroller.add(self.canvas)
        self.h_adj = self.scroller.get_hadjustment()
        self.v_adj = self.scroller.get_vadjustment()

        self.add(self.scroller)


    def on_button_pressed(self, src, tgt, event):
        """ Cuando se oprime el boton del mouse, creamos una instancia del
            objeto seleccionado
        """
        # Pero solo si es el boton 1:
        if event.button == 1:
            scale = self.zoom.get_zoom()
            cube = Cube(self.cvroot, 30, 40, 50, event.x, event.y, 0)
            print(cube)
            self.items.append(cube)


    def on_wheel_scroll(self, src, tgt, event):
        """ Cuando se rota la rueda del mouse cambia la escala
        """
        if event.direction == Gdk.ScrollDirection.UP:
            self.zoom.zoom_in()

        else:
            self.zoom.zoom_out()

        self.center(event.x, event.y)

        # Aplicar el nuevo factor de zoom
        self.set_zoom(self.zoom.get_zoom())


    def center(self, x, y):
        hadj = self.scroller.get_hadjustment()
        vadj = self.scroller.get_vadjustment()

        hmin, hmax, value = hadj.get_lower(), hadj.get_upper(), hadj.get_value()
        print("limits:", hmin, hmax, value)

        hadj.set_value(x * self.zoom.get_zoom())
        vadj.set_value(y * self.zoom.get_zoom())


    def set_zoom(self, new_zoom):
        """ Cambiar el factor de escala:
            - cambiar la escala del canvas
            - actualizar la etiqueta del zoom en el marco del panel
        """
        self.canvas.set_scale(new_zoom)

        label = "{} Zoom: {:.3g}".format(self.kind, new_zoom)
        self.set_label(label)



class Board(Gtk.Frame):
    """ El tablero de visualizacion:
            - tres paneles con vistas paralelas con los ejes X, Y, y Z
            - un panel previsto para vista perspectiva
    """
    def __init__(self):
        super(Board, self).__init__(
                    label = 'Board')

        grid = Gtk.Grid(
                    row_spacing = 2,
                    column_spacing = 4,
                    row_homogeneous = True,
                    column_homogeneous = True,
                    margin = 4)
        for x, y, kind in ((0, 0, 'XY'),
                           (0, 1, 'YZ'),
                           (1, 0, 'ZX'),
                           (1, 1, 'PP')):
            view = View(kind)
            grid.attach(view, x, y, 1, 1)

        self.add(grid)


class MainWindow(Gtk.Window):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.connect("destroy", lambda x: Gtk.main_quit())
        self.set_size_request(700, 500)

        self.main_menu = Main_menu( ['_File', 'Edit', 'Help'] )
        self.main_menu.add_items_to('_File', [
                    ('Quit', self.on_file_quit)])
        self.main_menu.add_items_to('Help', [
                    ('About...', self.on_help_about)])

        self.tools = Tools()
        self.board = Board()

        hbox = Gtk.HBox(
                    spacing = 5,
                    margin = 4)
        hbox.pack_start(self.tools, False, False, 0)
        hbox.pack_start(self.board, True, True, 0)

        vbox = Gtk.VBox()
        vbox.pack_start(self.main_menu, False, False, 0)
        vbox.pack_start(hbox, True, True, 0)

        self.add(vbox)
        self.show_all()


    def run(self):
        Gtk.main()


    def on_file_quit(self, menuitem):
        Gtk.main_quit()


    def on_help_about(self, menuitem):
        pass


def main(args):
    mainwdw = MainWindow()
    mainwdw.run()

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
