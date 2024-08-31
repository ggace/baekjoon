from math import *

rest = 1_000_000_007

def my_pow(n, k):

    global rest
    if(k == 0):
        return 1;
    p = my_pow(n, k//2) % rest
    if(k%2):
        return (((p*p)% rest)*(n%rest)) % rest
    else:
        return (p*p) % rest

n, m = map(int, input().split())

t = 1;

for i in range(n):
    t *= 2
    t %= rest

if(t < m) :
    print(1)
    exit()


t_factorial = 1;

for i in range(1, t+1):
    t_factorial *= i
    t_factorial %= rest;


a = 1;

for i in range(1, t-m+1) :
    a *= i
    a %= rest

a_1 = my_pow(a, rest-2);
t_m = my_pow(t, m);
t_m1 = my_pow(t_m, rest-2)



son = ((t_m * a) % rest - t_factorial) % rest
if(son < 0) :
    son += rest

mom = (a_1 * t_m1) % rest

print((son * mom) % rest)
