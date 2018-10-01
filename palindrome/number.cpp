#include<iostream>
#include<cstring>
using namespace std;
int main()
{
string str,st;
int i,j,flag=1;
cin>>str;
int l =str.size();
for(i=0;i<l;i++)
st[i]=str[i];
for(i=l-1;i>=0;i--)
{
cout<<st[i];
}
for(j=0,i=l-1;i>=0,j<l;i--,j++ )
if(str[j]!=st[i])
{
    flag=0;
}
if(flag==1)
{
    cout<<"\npalindrome";
}
else
    cout<<"\nnot a palindrome";
}
