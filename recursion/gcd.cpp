#include<bits/stdc++.h>
using namespace std;

int recursive_gcd(int a, int b) {                       // DIVIDEND = a         DIVISOR = b
    if(b==0)
        return a;
    return recursive_gcd(b,a%b);                        // DIVIDEND BECOMES 'b' AND DIVISOR BECOMES 'remainder'
}

int main()
{
    int a,b;
    cin>>a>>b;
    int c = recursive_gcd(a,b);
    cout<<c<<"\n";
    return 0;
}