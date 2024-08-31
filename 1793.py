dp = [0 for i in range(251)]

def main():
    n = int(input())
    for i in range(3, n+1):
        if(dp[i] == 0):
            #print(f"{i}: {dp[i-1] + dp[i-2] * 2}")
            dp[i] = dp[i-1] + dp[i-2] * 2
        else:
            continue;
    print(dp[n]);


dp[0] = 1
dp[1] = 1
dp[2] = 3
while(True):
    try:
        main()
    except:
        break;
