def solution():
    a = input()
    b = input()

    a_result = go(a);
    b_result = go(b);

    if(a_result > b_result):
        print('>')
    elif(a_result == b_result):
        print('=')
    else:
        print("<")

def go(s):
    if(len(s) == 0):
        return 0;
    if s[0] == ')':
        return 0;
    if s[0] == '(' and s[1] == ')':
        return 1 + go(s[2:])
    if s[0] == '(' and s[1] == '(':
        return 2 * go(s[1:])

n = int(input())

for i in range(n):
    solution()


