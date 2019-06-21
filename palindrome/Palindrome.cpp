#include<bits/stdc++.h>
using namespace std;
int main()
{
  string n;
  cin >> n;
  int flag = 0;
  for ( int i = 0; i < n.length()/2; i++ )
  {
     if ( n[i] != n[ n.length() - 1 - i ])
     {
        flag = 1;
        break;
     }
  }
  
  if ( flag == 0 )
  {
    cout << "A PALINDROME" << endl;
  }
  else
  {
    cout << "NOT A PALINDROME" << endl;
  }
  
  return 0;
}
