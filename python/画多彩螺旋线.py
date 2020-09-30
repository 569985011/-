#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-10-04 23:07:43
# @Author  : Chauncy (chauncy523@gmail.com)
# @Link    : 
# @Version : $Id$

import turtle
import time
turtle.pensize(2)
turtle.bgcolor('black')
colors=['red','yellow','blue','pink']
turtle.tracer(False)
for x in range(400):
	turtle.forward(2*x)
	turtle.color(colors[x%4])
	turtle.left(91)
turtle.tracer(True)
time.sleep(10)
