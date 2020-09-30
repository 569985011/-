#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-10-20 21:49:43
# @Author  : Chauncy (chauncy523@gmail.com)
# @Link    : 
# @Version : $Id$

import urllib.request, re, math,time
from bs4 import BeautifulSoup
from urllib.robotparser import RobotFileParser

def Robot(code):
	html=RobotFileParser()
	html.set_url('http://fund.eastmoney.com/%s.html'%code)
	html.read()
	print(html.can_fetch('*',html.url))
	return(html.can_fetch('*',html.url))

def calc(code):
	if(Robot(code)!= True):
		print("不可抓取")
		return()
	html = urllib.request.urlopen('http://fund.eastmoney.com/%s.html'%code)
	print(html.status)
	
	print(type(html))
	Response=html.read()
	Response = Response.decode('utf-8','ignore')

	soup = BeautifulSoup(Response, 'lxml')   #文档对象

	data=[]#列表
	time.sleep(2)
	print(code)
	ee=soup.find('span',id='gz_gztime')
	print("--净值估算时间%s"%ee.string)
	
	k = soup.find('span',id='gz_gsz')#,string='更多'
	print("--估算净值%s\n"%k.string)



                

print("begin:")
calc('006597')
