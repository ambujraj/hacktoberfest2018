#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int a,b;
    cout<<"Enter the number : ";
    cin>>a;
    b = sqrt(a);
    if(a == b*b ){
        cout<<"Perfect square.";
    }
    else{
        cout<<"Not a perfect square.";
    }
    return 0;
}
