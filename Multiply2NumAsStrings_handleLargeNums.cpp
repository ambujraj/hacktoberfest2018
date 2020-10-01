#include <bits/stdc++.h>
using namespace std;

string mult(string larger, string smaller,int base)
{
    long int n1 = larger.length();
    long int n2 = smaller.length();
    if (n1 == 0 || n2 == 0)
        return "0";

    vector<int> result(n1 + n2, 0); // will be in reverse order
    long int i_n1 = 0;
    long int i_n2 = 0;

    // Go from right to left in num1
    for (long int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int d_n1 = (int)(larger[i]) - 48;

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (long int j=n2-1; j>=0; j--)
        {
            int d_n2 = (int)(smaller[j]) - 48;
            int sum = d_n1*d_n2 + result[i_n1 + i_n2] + carry;
            carry = sum/base;

            result[i_n1 + i_n2] = sum % base; //store
            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }

    // ignore '0's from the right
    long int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
        i--;
    if (i == -1)
        return "0";

    // generate the result string
    string s = "";
    while (i >= 0)
        s += to_string(result[i--]);

    return s;
}

int main()
{
    string larger = "52000330341251624652264";
    string smaller = "31";
    int base = 7;
    cout<<"Enter larger number : ";
    cin>>larger;
    cout<<"Enter smaller number : ";
    cin>>smaller;
    cout<<"Enter base : ";
    cin>>base;
    cout<<"\nResult : "<<mult(larger, smaller, base)<<"\n";
    return 0;
}
