#!/usr/bin/python
# -*- coding: utf-8; -*-
#
# "THE BEER-WARE LICENSE" (Revision 42):
# <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
# you can do whatever you want with this stuff. If we meet some day, and you
# think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann

from random import randint
import sys

maxx = 2**30-1
for i in range(1,11):
    f = open('../testdata/subtask1/%02d.in' % i, 'w')
    n = randint(0, maxx)
    m = randint(0, maxx)
    f.write('%d %d' % (n,m))

maxx = 2**62-1
for i in range(1,11):
    f = open('../testdata/subtask2/%02d.in' % i, 'w')
    n = randint(0, maxx)
    m = randint(0, maxx)
    f.write('%d %d' % (n,m))



