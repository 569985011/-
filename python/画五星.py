#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-10-04 22:52:15
# @Author  : Chauncy (chauncy523@gmail.com)
# @Link    : 
# @Version : $Id$

from turtle import *
fillcolor("red")
begin_fill()
while True:
	forward(200)
	right(144)
	if abs(pos())< 1 :
		break
end_fill()
