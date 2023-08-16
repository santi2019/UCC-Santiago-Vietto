#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  mod_menu.py
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


import gi
gi.require_version('Gtk', '3.0')
gi.require_version('GooCanvas', '2.0')
from gi.repository import Gtk, GooCanvas


class Main_menu(Gtk.MenuBar):
    """ Esta clase crea un menu, con la siguiente filosofia:
            - Los items principales (File, Edit, etc) se crean en el momento
              de la instanciacion
            - Las aread de programa que desean agregar items a los items
              principales, lo pueden agregar posteriormente.
        El constructor espera una lista de los items principales.
        El metodo 'add_items_to' agrega sub-items a los item principal mediante
        una lista de tuplas
            - Si el primer elemento es None, se 'fabrica' un item separador
            - Caso contrario, se espera el nombre del item, y un 'handler'
              que se ejecutara.
    """
    def __init__(self, items = []):
        super(Main_menu, self).__init__()
        self.main_menu = {}

        for item in items:
            mitem = Gtk.MenuItem(
                        label = item,
                        use_underline = True)
            self.main_menu[item] = Gtk.Menu()
            mitem.set_submenu(self.main_menu[item])
            self.add(mitem)


    def add_items_to(self, main_item, items):
        for item, handler in reversed(items):
            if item == None:
                it = Gtk.SeparatorMenuItem()
            else:
                it = Gtk.ImageMenuItem(
                            label = item,
                            use_underline = True)
                it.connect("activate", handler)

            self.main_menu[main_item].insert(it, 0)



class MainWindow(Gtk.Window):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.connect("destroy", lambda x: Gtk.main_quit())
        self.set_default_size(400, 300)

        menu = Main_menu(['Archivos', 'Editar', 'Ayuda'])

        self.add(menu)
        self.show_all()

    def run(self):
        Gtk.main()


def main(args):
    mainwdw = MainWindow()
    mainwdw.run()

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
