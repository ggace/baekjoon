l = []
for i in range(5):
    l.append(int(input()))
a, x, b, y, t = l

if(t > 30):
    r1 = a + (t - 30)*x * 21
else:
    r1 = a

if(t > 45):
    r2 = b + (t-45) * y * 21;
else:
    r2 = b;

print(f"{r1} {r2}")
