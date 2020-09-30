import sys
import datetime

def parse_iso_str_to_datetime(s):
    return datetime.datetime.fromisoformat(s)


while True:
    line = sys.stdin.readline()
    line = line.strip()
    if line == '':
        break
    print(parse_iso_str_to_datetime(line).timestamp())
