def computeHCF(x, y):

   # This function implements the Euclidian algorithm to find H.C.F. of two numbers
   while(y):
       x, y = y, x % y

   return x
