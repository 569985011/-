from datetime import datetime
import sys

def get_month_range(date):
    FirstDay = datetime(date.year,date.month,1)
    NextDay =  datetime(date.year,date.month+1,1)
    
    return (FirstDay.timestamp() , NextDay.timestamp() )


while True:
    line = sys.stdin.readline()
    line = line.strip()
    if line == '':
        break
    date = datetime.strptime(line, "%Y-%m-%d")
    print(get_month_range(date))
