// Calculate trailing zeroes
// in factorial of given number
// For example: 5! = 120
// So trailing zeroes in 5! is 1

#include<iostream>
using namespace std;

int main() {
    int n, count=0;
    cout << "Enter the number \n";
    cin >> n;

    for(int i=5; n/i >= 1; i *= 5)
    {
        count += n/i;
    }

    cout << "Number of trailing zeroes in " << n << "! is " << count << endl;
    return 0;
}