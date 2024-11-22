from typing import List, Tuple
import math
from matplotlib import pyplot as plt

# 기본 자료형 타입 정의
ld = float
ll = int
ull = int
pii = Tuple[int, int]
pll = Tuple[ll, ll]

# PRIME_SIZE 상수 정의
PRIME_SIZE = 5

# 파이 상수 정의
PIE = 3.141592653589793

# Direction 클래스 정의
class Direction:
    def __init__(self, dx: int = 0, dy: int = 0):
        self.dx = dx
        self.dy = dy

# Position 클래스 정의
class Position:
    def __init__(self, x: int = 0, y: int = 0):
        self.x = x
        self.y = y

# 빠른 거듭제곱 함수 정의
def fastpow(a: ll, n: ll, c: ll) -> ll:
    result = 1
    while n:
        if n & 1:
            result *= a
            if result >= c:
                result %= c
        a *= a
        if a >= c:
            a %= c
        n >>= 1
    return result

# 소수 리스트와 소수 판별 배열 초기화
prime_list: List[ll] = []
is_prime = [True] * (PRIME_SIZE + 1)
is_prime[0] = is_prime[1] = False  # 0과 1은 소수가 아님

# 에라토스테네스의 체 구현
def siv(n: ll):
    for i in range(2, n + 1):
        if not is_prime[i]:
            prime_list.append(i)
        for p in prime_list:
            if i * p > n:
                break
            is_prime[i * p] = False
            if i % p == 0:
                break

# 변수 초기화
x: List[int] = []
y: List[int] = []
g: List[int] = []
bias = [0.0, 0.0]

def main():
    # fio
    n = int(input("Enter n: "))

    theta = 2 * PIE / n

    x = list(map(int, input().split()))
    y = list(map(int, input().split()))

    # 두 리스트의 합을 g에 추가
    for i in range(n):
        g.append(x[i] + y[i])

    x_list = []
    y1_list = []
    y2_list = []
    y_res_list = []

    for fre in range(2, n) :
        
        f =1/fre;
        x_list.append(fre)
        res1 = [0,0]
        res2 = [0,0]
        for k in range(math.lcm(n, fre)):
            res1[0] += x[k % n] * math.cos(2*math.pi * k * f)
            res1[1] += x[k % n] * math.sin(2*math.pi * k * f)
            res2[0] += y[k % n] * math.cos(2*math.pi * k * f)
            res2[1] += y[k % n] * math.sin(2*math.pi * k * f)


        temp1 = math.sqrt(pow(res1[0], 2) + pow(res1[1], 2)) / math.lcm(n, fre)
        temp2 = math.sqrt(pow(res2[0], 2) + pow(res2[1], 2)) / math.lcm(n, fre)
        print(f"{fre} : {temp1}, {temp2} - {temp1 + temp2}")
        y1_list.append(temp1)
        y2_list.append(temp2)
        y_res_list.append(temp1 + temp2)
    
    plt.plot(x_list, y1_list)
    plt.plot(x_list, y2_list)
    plt.plot(x_list, y_res_list)
    plt.show()
    

if __name__ == "__main__":
    main()
