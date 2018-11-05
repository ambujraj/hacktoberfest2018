//import libraries
#include <iostream>

using namespace std;
//call fibonacci function
int fibo(int);
//************************
int main()
{
    cout<<"Enter a number: ";
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        cout<<fibo(i);
    }
    return 0;
}

//make fibonacci function
int fibo(int a){
    if(a<2){
        return a;
    }
    else{
        return fibo(a-1)+fibo(a-2);
    }
}
