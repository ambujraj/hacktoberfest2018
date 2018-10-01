/*
Made By: Keshav Gupta

*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

int n;

cout<<"Enter the array length";
cin>>n;

int arr[n+1];
cout<<"Enter the array elements"<<endl;

for(int i=0;i<n;i++){
cin>>arr[i];
}

for(int i=0;i<n-1;i++)
{
int mini=i;

for(int j=i+1;j<n;j++)
{
if (arr[j] < arr[mini]) 
         {   mini= j; 
  }
        
}
 swap(arr[mini],arr[i]);

}

cout<<"New sorted array is "<<endl;
for(int i=0;i<n;i++){
cout<<arr[i]<<" ";
}






return 0;
}
