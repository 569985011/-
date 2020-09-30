#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-10-07 22:26:33
# @Author  : Chauncy (chauncy523@gmail.com)
# @Link    : 
# @Version : $Id$
#!/usr/bin/env python

import urllib.request, re, math

def calc(code):
    html = urllib.request.urlopen('http://www.ourku.com/nvhiList.php?code=%s' % (code)).read()
    r = re.compile(r'\<td\>(.+?)\</td\>')

    data = []
    i = 0
    html=html.decode('utf-8','ignore')#编码中出现部分不可识别的错码
    for d in r.findall(html, re.S):
        if i % 3 == 1:
            data.append(float(d))
        i += 1

    if len(data) == 0:
        return

    sum = 0.
    for d in data:
        sum += d

    avg = sum / len(data)
    difsum = 0.
    for d in data:
        difsum += math.fabs(d - avg)

    print ("%s,%2.4f,%2.4f" % (code, avg, difsum / len(data)))
        
print("基金代码，平均净值，平均差")
calc('162206')
calc('519506')
calc('519505')
calc('202302')
calc('160609')
calc('040003')
calc('100028')
calc('161608')
calc('320002')
calc('482002')
calc('050003')
calc('519999')
calc('217004')
calc('340005')
calc('202301')
calc('160606')
calc('091005')
calc('100025')
calc('163802')
calc('200003')
calc('090005')
calc('410002')
calc('240007')
calc('350004')
calc('240006')
calc('080011')
calc('020007')
calc('37001b')
calc('310338')
calc('519517')
calc('290001')
calc('519508')
calc('180009')
calc('400005')
calc('370010')
calc('519518')
calc('163303')
calc('180008')
calc('530002')
calc('260102')
calc('550011')
calc('550010')
calc('150015')
calc('150005')
calc('519510')
calc('519509')
calc('660107')
calc('660007')
calc('070008')
calc('880002')
calc('952001')
calc('110016')
calc('583101')
calc('253051')
calc('270004')
calc('110006')
calc('583001')
calc('253050')
calc('952010')
calc('003003')
calc('519589')
calc('213909')
calc('128011')
calc('360003')
calc('519588')
calc('213009')
calc('121011')
calc('288101')
calc('560001')
calc('460106')
calc('460006')