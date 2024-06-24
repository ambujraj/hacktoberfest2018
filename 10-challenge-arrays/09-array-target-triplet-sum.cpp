#include <iostream>
#include <algorithm>
using namespace std;

int pair_sum(int a[], int i, int n, int sum){
	int left = i+1, temp;
	int right = n-1;
	while(left<right){
		temp = a[left] +a[right];
		if(temp == sum)
			cout<<a[i]<<", "<<a[left++]<<" and "<<a[right--]<<endl;
		else if(temp>sum)
			right--;
		else
			left++;
	}
}

int triplet_sum(int a[], int n, int sum){
	for(int i=0; i<n;i++){
		pair_sum(a,i,n-i,sum-a[i]);
	}
}


int main(){
	// method 2
	int n, sum;
	cin>>n;
	int a[n];
	// read array
	for(int i=0;i<n;i++)
		cin>>a[i];
	// read sum
	cin>>sum;
	// sort using inbuilt function
	sort(a,a+n); 
	// triplet sum
	triplet_sum(a, n, sum);

	return 0;
}

/*

9
5 7 9 1 2 4 6 8 3
10
output
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5

*/