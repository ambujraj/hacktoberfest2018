tamHeap = 0

def esquerda(i):
  return (2 * i) + 1

def direita(i):
  return (2 * i) + 2

def refaz_heap_max(A, i):
  global tamHeap
  e = esquerda(i)
  d = direita(i)
  maior = i

  if e <= tamHeap and A[e] > A[maior]:
    maior = e
  if d <= tamHeap and A[d] > A[maior]:
    maior = d
  if maior != i:
    aux = A[i]
    A[i] = A[maior]
    A[maior] = aux
    refaz_heap_max(A, maior)

def constroi_heap_max(A):
  global tamHeap
  flag = 0
  tamHeap = len(A) - 1
  i = (int)(tamHeap/2)

  while i >= 0:
    refaz_heap_max(A, i)
    i -= 1
    if flag == 1:
      break
    if i == 0:
      flag = 1

def heap_sort(A):
  global tamHeap
  constroi_heap_max(A)

  for i in range(len(A) - 1, 0, -1):
    aux = A[0]
    A[0] = A[i]
    A[i] = aux
    tamHeap = tamHeap - 1
    refaz_heap_max(A, 0)
