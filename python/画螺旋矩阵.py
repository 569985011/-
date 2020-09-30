#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-10-04 23:00:09
# @Author  : Chauncy (chauncy523@gmail.com)
# @Link    : 
# @Version : $Id$

import turtle 
import time
turtle.speed('fast')
turtle.pensize(2)
for x in range(100):
	turtle.forward(2*x)
	turtle.left(90)
time.sleep(100)
