import datetime

moscow_time = datetime.datetime(2019, 3, 18, 18, 13, 27)
lundon_time = moscow_time-datetime.timedelta(hours=+3)
beijing_time =lundon_time+datetime.timedelta(hours=+8)
tokyo_time =lundon_time+datetime.timedelta(hours=+9)
newyork_time =lundon_time+datetime.timedelta(hours=-4)

print("伦敦 "+datetime.datetime.strftime(lundon_time,"%Y-%m-%d %H:%M:%S"))
print("北京 "+datetime.datetime.strftime(beijing_time,"%Y-%m-%d %H:%M:%S"))
print("东京 "+datetime.datetime.strftime(tokyo_time,"%Y-%m-%d %H:%M:%S"))
print("纽约 "+datetime.datetime.strftime(newyork_time,"%Y-%m-%d %H:%M:%S"))
