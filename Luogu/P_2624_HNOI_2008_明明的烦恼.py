def fact(n) :
    ans = 1
    for i in range(1, n+1):
        ans = ans * i
    return ans
n = int(input())
deg = []
ans = 1
tot = 0
sm = 0
sn = 0
for i in range (0, n):
    t = int(input())
    deg.append(t)
    if t != -1 :
        sn = sn + t - 1
    if t == 0 :
        sn = 998244353
if sn > n-2:
    print(0)
else :
    ans = fact(n - 2)
    for t in deg :
        if t == -1 :
            tot = tot + 1
        else :
            ans = ans // fact(t - 1)
            sm += t-1
    ans = ans * pow(tot, n - 2 - sm) // fact(n - 2 - sm)
    print(ans // 1)