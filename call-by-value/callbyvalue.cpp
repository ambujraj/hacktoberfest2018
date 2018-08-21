#include <iostream>
using namespace std;
int sum(int a, int b)
{
    int sum = a + b;
    cout << sum;
}
int main()
{
    int x, y;
    cin>>x>>y;
    sum(x, y);
}
