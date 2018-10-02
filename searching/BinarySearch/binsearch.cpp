/**
* Binary Search
* Author: Omkar Manjrekar
**/
#include<iostream>
#include<stdlib.h>
using namespace std;

int binsearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) 
    { 
        int m = l + (r-l)/2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
    // if we reach here, then element was 
    // not present 
    return -1; 
} 

void sort(int arr[], int num) {
    int t;
    for (int i = 0; i < num; i++)
    {
        for (int j = i; j < num; j++)
        {
            if (arr[i] > arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int main()
{
    int a[20], n, key, pos=-1;
    cout<<"Enter the number of elements: ";
    cin>>n;

    cout<<"Enter the Elements"<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    sort(a, n);
    cout<<"Sorted Elements"<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

    cout<<endl<<"Enter the Key to Search: ";
    cin>>key;

    pos = binsearch(a, 0, n-1, key);
    if(pos != -1) {
        cout<<"Query is found at location: "<<pos<<endl;
    }
    else{
        cout<<"key not Found";
    }
    return 0;
}