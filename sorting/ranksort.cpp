#include<iostream>

using namespace std;


int main()
{
  int n;
 cin>>n;
  int a[n],u[n],r[n]={0};
for(int i=0;i<n;i++)
{
  cin>>a[i];
}

 
for(int j=0;j<n;j++)
{
  for(int i=0;i<j;i++)
  {
    if(a[i]<=a[j]) r[j]=r[j]+1;
    else r[i]=r[i]+1;
  }
}


for(int j=0;j<n;j++)
{
  u[r[j]]=a[j];
}


for(int i=0;i<n;i++)
{
  a[i]=u[i];
}

for(int i=0;i<n;i++)
{
 cout<<a[i]<<" ";
}




}
