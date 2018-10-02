// Implementation of bucket sort in C++ using array as as data structure

#include <iostream>

#define s 10

using namespace std;

void BucketSort(int arr[], int n)
{ int i, j, k, buckets[s];
  for(i=0; i<s; i++)
    buckets[i] = 0;
    
  for(i=0; i<n; i++)
    ++buckets[arr[i]];
  
  for(i=0, j=0; j<s; ++j)
  { for(k = buckets[j]; k>0; k--)
      arr[i++] = j;
  }
} 

int main()
{ int n, i, arr[50];
  cout<<"enter the number of array elements";
  cin>>n;
  cout<<"enter the array elements";
  for(i=0; i<n; i++)
    cin>>arr[i];
    
  BucketSort(arr, n);
  
  cout<<"the sorted array is";
  for(i=0; i<n; i++)
    cout<<arr[i]<<"\t";
  
  return 0;
}
