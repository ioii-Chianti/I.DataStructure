_ = input()
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

cnt = 0

for a in A:
    for b in B:
        if a < b:
            continue
        for c in C:
            if b < c:
                cnt += 1
print(cnt)