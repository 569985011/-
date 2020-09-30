from datetime import datetime
import sys


def to_readable_time(date, now):
    TimeSpan = now - date
    if TimeSpan.days > 30 :
        return datetime.strftime(date,"%Y-%m-%d %H:%M:%S")
    elif TimeSpan.days> 6 :
        return str(int(TimeSpan.days/7))+" 周前"
    elif TimeSpan.days> 0 :
        return str(TimeSpan.days)+" 天前"
    elif TimeSpan.seconds >59 :
        return str(int(TimeSpan.seconds/60))+" 分钟前"
    else:
        return str(TimeSpan.seconds)+" 秒前"

while True:
    line = sys.stdin.readline()
    line = line.strip()
    if line == '':
        break

    print(to_readable_time(
        datetime.strptime(line, '%Y-%m-%d %H:%M:%S'),
        datetime.strptime('2019-03-18 12:00:00', '%Y-%m-%d %H:%M:%S')))
