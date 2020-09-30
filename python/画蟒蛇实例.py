#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-10-07 07:13:07
# @Author  : Chauncy (chauncy523@gmail.com)
# @Link    : 
# @Version : $Id$

import turtle

def Pencolor(color):
	r,g,b =color
	return int(r), int((g+25)%255) ,int(b)
	


def drawSnake(rad,angle,len,neckrad):
	turtle.colormode(255)
	turtle.pencolor(0,255,255)


	for i in range(len):
		turtle.circle(rad,angle)
		turtle.pencolor(Pencolor(turtle.pencolor()))
		turtle.circle(-rad,angle)
		turtle.pencolor(Pencolor(turtle.pencolor()))

	#画蟒蛇头
	turtle.pencolor("purple")
	turtle.circle(rad,angle/2)	
	turtle.fd(rad)
	turtle.circle(neckrad+1,180)
	turtle.fd(rad*2/3)

'''
	#画圆
	# turtle.colormode(255)
	for i in range(18):
		# turtle.pencolor(Pencolor(turtle.pencolor()))
		turtle.left(10)
		turtle.fd(3)
'''
def main():
	turtle.setup(650,350,200,200)
	pythonsize = 25
	turtle.pensize(pythonsize)
	
	turtle.seth(-40)
	drawSnake(40,80,5,pythonsize/2)

main()
