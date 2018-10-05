int factorial(int n)
{
 int fact=1;
 for(int i=1;i<=n;i++)
  fact=fact*i;
  return fact;
}
void main()
{
  int fac=factorial(4);
  print('factorial ${fac}');
}


