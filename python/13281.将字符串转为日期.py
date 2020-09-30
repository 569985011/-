import datetime

# 2019-3-18
print(datetime.datetime.strptime(input(), "%Y-%m-%d"))

# 18 Mar 2019
print(datetime.datetime.strptime(input(), "%d %b %Y"))

# 19-03-18
print(datetime.datetime.strptime(input(), "%y-%m-%d"))

# 2019-03-18 14:03:15
print(datetime.datetime.strptime(input(), "%Y-%m-%d %H:%M:%S"))

# 2019-03-18 02:03:15PM
print(datetime.datetime.strptime(input(), "%Y-%m-%d %I:%M:%S%p"))

# 2019-03-18 14:03:15.123456

print(datetime.datetime.strptime(input(), "%Y-%m-%d %H:%M:%S.%f"))


# 2019-03-18%14:03:15
print(datetime.datetime.strptime(input(), "%Y-%m-%d%%%H:%M:%S"))
