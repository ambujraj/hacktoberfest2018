#include <iostream>

using namespace std;

int mod;

long long modPow(long long a, long long x) {
    //calculates a^x mod mod in logarithmic time.
    long long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        x /= 2;
    }
    return res;
}

int main(){

    int a,b;
    cin>>a>>b>>mod;

    cout<<modPow(a,b)<<endl;
}
