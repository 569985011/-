import sys

def is_leap_year(y):
        #每四年加一天，每100年减1天，每400年加一天，每3200减1天
    return  (y%400==0 and y%3200!=0) or (y%100!=0 and y%4==0 )
    

while True:
    line = sys.stdin.readline()
    line = line.strip()
    if line == '':
        break
    print(is_leap_year(int(line)))
