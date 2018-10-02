// Implementation of radix sort in C++ using array as data structure

#include <iostream>
#include <math>

using namespace std;

int getMax(int arr[], int n)
{ int max = arr[0];
  for(int i = 1; i<n; i++)
  { if(arr[i] > max)
      max = arr[i];
  }
  return max;
}

void CountSort(int arr[], int n, int exp)
{ int output[n], i, count[10] = {0};
  for(i=0; i<n; i++)
  { count[(arr[i]/exp)%10]++; 
  }
  for(i=0; i<10; i++)
  { count[i] += count[i-1];
  }
  for(i=n-1; i>=0; i--)
  { output[count[(arr[i]/exp%10]-1] = arr[i];
    count[(arr[i]/exp)%10]--;
  }
  for(i=0; i<n; i++)
    arr[i] = output[i];
}

void radixsort(int arr[],int n)
{ int exp, m;
  m = getMax(arr, n);
  for( exp=1; m/exp > 0; exp *= 10)
    CountSort(arr, n, exp);
}

int main()
{ int n,i,arr[50];
  cout<<"enter the number of array elements";
  cin>>n;
  cout<<"enter the array elements";
  for(i=0; i<n; i++)
    cin>>array[i];
  
  radixsort(array,n);
  
  cout<<"the sorted array is";
  for(i=0; i<n; i++)
    cout<<array[i]<<"\t";
  
  return 0;
}
