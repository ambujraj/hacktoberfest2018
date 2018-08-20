#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int num, fact;
    char c;
    while(true){
    fact = 1;
    cout<<"Enter the number you want to find factorial of: ";
    cin>>num;
    if(num==0){
        fact = 1;
    }
    else if(num==1){
        fact = 1;
    }
    else{
        for (int i=num;i>0;i--){
            fact = fact*i;
        }
    }
    cout<<"Factorial of "<<num<<" is: "<<fact<<endl;
    cout<<"Do You Want to Enter another number?(y/n): ";
    cin>>c;
    if(c=='n' || c=='N'){
        exit(0);
    }
    else{
        continue;
    }
    }
}
