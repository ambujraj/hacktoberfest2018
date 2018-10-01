#include <iostream>

template <int N> int Fib(){ return Fib<N-1>() + Fib<N-2>(); }
template <> int Fib<1>() { return 1; }
template <> int Fib<0>() { return 1; }

using namespace std;
int main()
{
  int num = 0;
  cout << "Enter the number of terms: ";
  cin >> num;
  cout << "The fibonacci series: ";
  cout << Fib<num>() << endl;
  return 0;
}
