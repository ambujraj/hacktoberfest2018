#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int reverse(int n, int k)
{
    if(n == 0)
        return k;
    k = (k*10) + (n%10);
    return reverse(n/10, k);
}
int main()
{
    int n;
    cin>>n;
    int ans = reverse(n, 0);
    cout<<ans;
}
    
