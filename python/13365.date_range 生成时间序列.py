import datetime
import sys

def date_range(start_date, peroids, days=0, seconds=0, microseconds=0,
               milliseconds=0, minutes=0, hours=0, weeks=0):
    a= []
    for p in range(1,peroids+1):
        a.append(start_date+ datetime.timedelta(days=days*p,
                            seconds=seconds*p,
                            microseconds=microseconds*p,
                            milliseconds=milliseconds*p,
                            minutes=minutes*p,
                            hours=hours*p,
                            weeks=weeks*p
                            ))
    #print(a)
    
    return a



start = datetime.datetime.strptime('2019-03-22 12:00:00', '%Y-%m-%d %H:%M:%S')

for d in date_range(start, 5, days=1):
    print(d)
print('-------------------')
for d in date_range(start, 5, minutes=2):
    print(d)
print('-------------------')
for d in date_range(start, 5, weeks=3, hours=1):
    print(d)
