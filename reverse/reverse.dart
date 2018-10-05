int reverse(int n)
{
 int rev=0;
  while(n!=0)
  {
    int p=n%10;
    int q=n-p;
    rev=rev*10+p;
    n= (q/10).floor();
  }
  return rev;
  
}
void main()
{
  int r=reverse(87852);
  print('reverse ${r}');
}

