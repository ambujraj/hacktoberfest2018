#include <iostream>

using namespace std;

int factorial (int n)
{
    if(n==1)
    {
        return 1;
    }
    return n*factorial(n-1);

}
int main()
{
    int n,result;
    cin>>n;
    result=factorial(n);
    cout<<result;
    return 0;

}
