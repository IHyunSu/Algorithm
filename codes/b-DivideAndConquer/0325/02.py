import math

def large_mult(u, v):
    global cnt
    cnt += 1
    n = max(len(str(u)), len(str(v)))
    
    if u == 0 or v == 0:
        return 0
    elif n <= threshold:
        return u * v
    else:
        m = n // 2
        x, y = divmod(u, 10**m)
        w, z = divmod(v, 10**m)
        
        p1 = large_mult(x, w)
        p2 = large_mult(x, z)
        p3 = large_mult(w, y)
        p4 = large_mult(y, z)
        
        return p1 * (10**(2*m)) + (p2 + p3) * (10**m) + p4

global threshold
threshold = int(input().strip())
u = input().strip()
v = input().strip()
global cnt
cnt = 0
    
result = large_mult(int(u), int(v))
print(cnt)
print(result)