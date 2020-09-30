#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-10-04 22:55:56
# @Author  : Chauncy (chauncy523@gmail.com)
# @Link    : 
# @Version : $Id$

from turtle import *
color('red','yellow')
begin_fill()
while True:
	forward(200)
	left(170)
	if abs(pos())<1:
		break
end_fill()
done()
