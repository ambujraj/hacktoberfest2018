n = int(input())
for cnt in range(n):
    a = 1
    for k in range(cnt + 1):
        print(a, end=' ')
        a *= (cnt - k)
        a //= (k + 1)
    print()
