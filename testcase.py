import random

n = random.randint(1, 70)

print(n)

for i in range(n):
    print(random.randint(0, 1000000), end=" ")

