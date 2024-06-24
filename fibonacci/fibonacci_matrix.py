def fibo(n):
  
  """
    returns the nth fibonacchi number
    1 -> 1
    2 -> 1
    3 -> 2
    4 -> 3
    5 -> 5
  """
  import numpy as np
  
  return np.linalg.matrix_power(a,n-1)[0][0]
  
