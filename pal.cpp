#include <iostream>

using namespace std;

int main()
{
    long a,rev,b;
    cout<<"\nenter the number :";
    cin>>a;
    b=a;
    rev=0;
    while(b)
    {
        rev=(rev*10)+(b%10);
        b=b/10;
    }
    if(a==rev)
        cout<<"\n the number IS a palindrome.";
    else
        cout<<"\n the number IS NOT a palindrome.";
    return 0;
}
