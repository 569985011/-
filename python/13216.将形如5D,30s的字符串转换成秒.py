def convert_to_seconds(time_str):
    # write code here
    if time_str[-1] in ['s','S']:
        return str(round(eval(time_str[0:-1])*1.0,2))
    elif time_str[-1] in ['m','M']:
        return str(round(eval(time_str[0:-1])*60.0,2))
    elif time_str[-1] in ['h','h']:
        return str(round(eval(time_str[0:-1])*3600.0,2))
    elif time_str[-1] in ['d','D']:
        return str(round(eval(time_str[0:-1])*24*3600.0,2))

while True:
    line = input()

    if line == '':
        break
    print(convert_to_seconds(line))
