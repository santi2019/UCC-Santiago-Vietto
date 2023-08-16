#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  parsing.py
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

import pyparsing as pp

def make_url_parser():
    protocolo = pp.Keyword("http") ^ pp.Keyword("https")
    dominio = pp.Word(pp.alphanums) + pp.OneOrMore("." + pp.Word(pp.alphanums))
    url = protocolo + "://" + dominio
    return url


def make_real_parser():
    sign = pp.oneOf("+ -")
    integer = pp.Word(pp.nums)
    exponente = pp.oneOf("e E") + pp.Optional(sign) + integer
    real = (pp.Optional(sign) + integer + pp.Optional("." + integer) +
            pp.Optional(exponente))
    real = pp.Combine(real).setParseAction(lambda toks: float(toks[0]))
    return real


def make_calculator():
    sign = pp.oneOf("+ -")
    integer = pp.Word(pp.nums)
    exponente = pp.oneOf("e E") + pp.Optional(sign) + integer
    real = (pp.Optional(sign) + integer + pp.Optional("." + integer) +
            pp.Optional(exponente))
    real = pp.Combine(real).setParseAction(lambda toks: float(toks[0]))

    mult_ops = pp.oneOf("* /")
    sum_ops = pp.oneOf("+ -")

    factor = real
    termino = factor + pp.ZeroOrMore(mult_ops + factor)
    formula = termino + pp.ZeroOrMore(sum_ops + termino)
    return formula

def main(args):
    urlp = make_url_parser()
    print(urlp)
    print(urlp.parse_string("http://kayak.jcoppens.com"))

    realp = make_real_parser()
    for test in ('0', '-1', '+2', '123.34', '+222.7', '4.5e5'):
       print(test, realp.parse_string(test))

    calc = make_calculator()
    for test in ('0', '-1', '+2', '123.34', '+222.7', '4.5e5',
                 '1+2', '1+2+3', '1+2*4', '3*5*12'):
        print(test, calc.parse_string(test))
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
