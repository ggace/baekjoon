number_counts = [0,0,0,0,0,0,0,0,0,0]

result = str(int(input()) * int(input()) * int(input()))

for r in result:
    number_counts[int(r)] += 1;

for i in range(0, 10):
    print(number_counts[i]);

