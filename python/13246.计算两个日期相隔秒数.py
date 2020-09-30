import datetime
import time

def date_delta(start, end):
    s=datetime.datetime.strptime(start, "%Y-%m-%d %H:%M:%S")
    e=datetime.datetime.strptime(end, "%Y-%m-%d %H:%M:%S")       
    return((e-s).days*24*3600+float((e-s).seconds))
    

start = input()  # sys.stdin.readline()
end = input()  # sys.stdin.readline()

print(date_delta(start, end))
