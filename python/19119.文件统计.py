
with open('latex.log', 'r', encoding='utf-8') as f:
    
    lines=0
    words=0
    for line in f:
        line = line.replace("\n","")
        
        if len(line)<2:
            continue
        lines+=1
        words+=len(line)
    f.close()
    print(int(round(words/lines,0)))
