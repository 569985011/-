import sys
import datetime


def next_day(date_str):
    d = datetime.datetime.strptime(date_str, "%Y-%m-%d")
    return (d + datetime.timedelta(days = 1)).strftime("%Y-%m-%d")    


def prev_day(date_str):
    d = datetime.datetime.strptime(date_str, "%Y-%m-%d")
    return (d + datetime.timedelta(days= -1)).strftime("%Y-%m-%d")   


while True:
    line = sys.stdin.readline()
    line = line.strip()
    if line == '':
        break
    print('前一天:', prev_day(line))
    print('后一天:', next_day(line))
