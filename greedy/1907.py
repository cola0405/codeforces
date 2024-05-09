t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a = list(reversed(a))*2
    p = [0]
    q = [0]
    for i in range(n*2-1):
        p.append(p[-1]+1 if a[i]>=a[i+1] else 0)
        q.append(q[-1]+1 if a[i]<=a[i+1] else 0)
    minn = 1000000
    for i in range(n-1,len(p)):
        if p[i] == n-1:
            minn = min(minn, i-n+1, len(p)-i+1)
        if q[i] == n-1:
            minn = min(minn, len(p)-i, i-n+2)
    print(-1 if minn == 1000000 else minn)