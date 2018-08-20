#include <iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the number of terms: ";
    cin>>num;
    int a[num];
    for(int i=0;i<num;i++)
    {
        if(i==0){
            a[i] = 0;

        }
        else if(i==1){
            a[i] = 1;
        }
        else{
        a[i] = a[i-1]+a[i-2];
    }}
    cout<<"The fibonacci series: ";
    for(int i=0;i<num;i++){
        cout<<a[i]<<" ";
    }
}