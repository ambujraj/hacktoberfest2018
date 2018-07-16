#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int a[20],n,key,pos=-1;
    cout<<"Enter the number of elements: ";
    cin>>n;
    system("cls");
    cout<<"Enter the Elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    system("cls");
    cout<<endl<<"Enter the Key to Search: ";
    cin>>key;
    for(int i=0;i<n;i++){
        if(key==a[i]){
            pos = i+1;
        }

    }
    if(key!=-1){
        cout<<"Query is found at location: "<<pos;

    }
    else{
        cout<<"key not Found";
    }
}
