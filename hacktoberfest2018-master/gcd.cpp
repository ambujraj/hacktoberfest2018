#include<bits/stdc++.h>
using namespace std;

int recursive_gcd(int a, int b) {                       // DIVIDEND = a         DIVISOR = b
    if(b==0)
        return a;
    return recursive_gcd(b,a%b);                        // DIVIDEND BECOMES 'b' AND DIVISOR BECOMES 'remainder'
}

int iterative_gcd(int a,int b) {
    int divi = a;
    int divisor = b;
    while(divisor != 0) {
        int rem = divi % divisor;
        divi = divisor;
        divisor = rem;
    }
    return divi;
}

int main()
{
    int a,b;
    cin>>a>>b;
    int c = recursive_gcd(a,b);
    cout<<c<<"\n";
    c = iterative_gcd(a,b);
    cout<<c<<"\n";
    return 0;
}