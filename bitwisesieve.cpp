#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define __FAST ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

pair<int,int> arah[8] = { {0,1} , {1,1} , {1,0} , {1,-1} , {0,-1} , {-1,-1} , {-1,0} , {-1,1} };

bool cmp (int i,int j) { return (i>j); }

const int ssize = int(1e8+3);
int prime[ssize/64];

// Checks whether x is prime or composite
bool ifnotPrime(int prime[], int x)
{
    // checking whether the value of element
    // is set or not. Using prime[x/64], we find
    // the slot in prime array. To find the bit
    // number, we divide x by 2 and take its mod
    // with 32.
    return (prime[x/64] & (1 << ((x >> 1) & 31)));
}
 
// Marks x composite in prime[]
bool makeComposite(int prime[], int x)
{
    // Set a bit corresponding to given element.
    // Using prime[x/64], we find the slot in prime 
    // array. To find the bit number, we divide x
    // by 2 and take its mod with 32.
    prime[x/64] |= (1 << ((x >> 1) & 31));
}
 
// Prints all prime numbers smaller than n.
void bitWiseSieve(int n)
{
    // Assuming that n takes 32 bits, we reduce
    // size to n/64 from n/2.
    // Initializing values to 0 .
    memset(prime, 0, sizeof(prime));
 
    // 2 is the only even prime so we can ignore that
    // loop starts from 3 as we have used in sieve of
    // Eratosthenes .
    for (int i = 3; i * i <= n; i += 2) {
 
        // If i is prime, mark all its multiples as
        // composite
        if (!ifnotPrime(prime, i))
            for (int j = i * i, k = i << 1; j < n; j += k)
                makeComposite(prime, j);
    }
}

int main() 
{ 
    bitWiseSieve(100000002);
    int n,x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        if (x==2 || (!ifnotPrime(prime, x) && x%2))
        {

            printf("0\n");
        } else {
            int temp = x;
            if (temp%2==0)
            {
                temp--;
            }
            while(1){
                if (ifnotPrime(prime, temp))
                {
                    temp-=2;
                } else {
                    break;
                }
                
            }
            printf("%d\n", (x-temp));
        }
        
    }
    return 0; 
}