import calendar


year = int(input())
month = int(input())

calendar.setfirstweekday(0)
calendar.prmonth(year, month, 2)
