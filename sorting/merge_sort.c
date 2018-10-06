
/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
#define ll long long int

//INPUT: enter number of numbers to be sorted and then enter the numbers
//OUTPUT: Sorted arrangement of numbers entered

void merge(ll arr[], ll l, ll m, ll r) 
{ 
    ll i, j, k; 
    ll n1 = m - l + 1; 
    ll n2 =  r - m; 
  

    ll L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) //equality ensures that it is a stable sort
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  

    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  

    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(ll arr[], ll l, ll r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        ll m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void printArray(ll A[],ll size) 
{ 
    ll i; 
    for (i=0; i < size; i++) 
        printf("%lld ", A[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    ll n,i;
    printf("Enter Size of Array to be sorted: ");
    scanf("%lld",&n);
    ll *arr=(ll *)malloc(sizeof(ll)*n);
    printf("Enter the elements to be sorted:\n");
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    mergeSort(arr, 0, n - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, n); 
    return 0; 
} 
