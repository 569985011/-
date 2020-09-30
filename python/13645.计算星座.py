import sys
from datetime import datetime

def zodiac(date):  
    zodiac_name=(u'摩羯座',u'水瓶座',u'双鱼座',u'白羊座',u'金牛座',u'双子座',
                u'巨蟹座',u'狮子座',u'处女座',u'天秤座',u'天蝎座',u'射手座',)
    zodiac_days=((1,20),(2,19),(3,20),(4,20),(5,21),(6,21),
                (7,23),(8,23),(9,23),(10,23),(11,22),(12,21))     #元组嵌套
    zodiac_day=list(filter(lambda x: x<(date.month,date.day),zodiac_days))
    zodiac_len=len(list(zodiac_day))%12
    #print(zodiac_day)
    #print(zodiac_len)
    return zodiac_name[zodiac_len]
 

while True:
    line = sys.stdin.readline()
    line = line.strip()
    if line == '':
        break
    print(zodiac(datetime.strptime(line, '%Y-%m-%d')))


    
