# coding: utf-8

termos = int(input('Quantos termos deseja ver ? '))
n1 = 0
n2 = 1
print(n1, "-", n2, end=' - ')
for fib in range(2, termos):
    n3 = n1 + n2
    n1 = n2
    n2 = n3
    print(n3, end=' - ')
print('FIM')
