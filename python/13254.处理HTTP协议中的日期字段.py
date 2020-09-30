import sys
import datetime


def parse_http_datetime(s):
    
    if '-'in s:
        return datetime.datetime.strptime(s,"%A, %d-%b-%y %H:%M:%S GMT")
    elif s[-1] in ['T']:
        return datetime.datetime.strptime(s,"%a, %d %b %Y %H:%M:%S GMT")
    else:
        return datetime.datetime.strptime(s,"%a %b %d %H:%M:%S %Y")


while True:
    line = sys.stdin.readline()
    line = line.strip()   #去除两端空格
    if line == '':
        break
    print(parse_http_datetime(line))
