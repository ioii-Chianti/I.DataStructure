N, K = map(int, input().split())
seq = list(map(int, input().split()))
ans = []

def Kth(end):
    newSeq = seq[0 : end]
    newSeq.sort()
    return newSeq[K-1]

for index in range(K, N+1):
    ans.append(Kth(index))

for it in ans:
    print(it, end=' ')