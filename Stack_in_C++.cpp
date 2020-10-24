#include<bits/stdc++.h>
using namespace std;
#define MAX 5
int a[MAX],top=-1;
void push(int x){
    if(top==MAX-1){
        cout<<"stack is overflow"<<endl;
    }
    else
    {
        a[++top]=x;
    }}
 void pop()
 {
     if(top==-1){
        cout<<"stack is underflow"<<endl;
     }
     else{
        a[top--];
     }}
void disp(){
    cout<<"elements are"<<endl;
    for(int i=0;i<=top;i++){
        cout<<a[i]<<" ";
    }}
int main()
{
    push(10);
    push(20);
    push(30);
    disp();
    pop();
    pop();
    disp();
   return 0;
}
