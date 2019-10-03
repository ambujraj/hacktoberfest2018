x = []
while True:
    p = input()
    p = int(p)
    if p == 0:
        break
    else:
        x.append(p)
for i in reversed(x):
    print(i)
