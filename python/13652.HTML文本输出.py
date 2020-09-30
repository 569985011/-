import sys


def remove_tags(raw_html):
    temp = ''
    Flag = False
    for i in range(len(raw_html)):
        if Flag :
            temp+=raw_html[i]
        if i == '>':
            Flag = True
        elif i == '<':
            Flag = False
        
    return temp

txt = ''
for line in sys.stdin:
    txt = txt + line

print(remove_tags(txt))
