s = input();
for a in input().split():
    if(a.islower()):
        s = s.replace(a, a.upper())
    else:
        s = s.replace(a, a.lower())

print(s)