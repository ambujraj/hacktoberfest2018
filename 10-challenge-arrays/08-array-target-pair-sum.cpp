#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	// method 2
	int n, left, right, sum, temp;
	cin>>n;
	int a[n];
	// read array
	for(int i=0;i<n;i++)
		cin>>a[i];

	// read sum
	cin>>sum;

	// sort using inbuilt function
	sort(a,a+n); // starting and ending address

	// printing pairs
	left = 0;
	right = n-1;
	while(left<right){
		temp = a[left] +a[right];
		if(temp == sum)
			cout<<a[left++]<<" and "<<a[right--]<<endl;
		else if(temp>sum)
			right--;
		else
			left++;
	}

	return 0;
}

/*

Method 1: o(n2) brute froce
for each elements check each element next to it;
this may give duplicate result.

Method 2: o(n)
Sort the array;
take 2 pointers left and right
if sum>required sum then decrease right pointer
else increase left pointer.
this may also give duplicate answer.

e.g 1:

5
1 3 4 2 5
5

pairs:
1 and 4
2 and 3

e.g 2:

4
2 3 3 2
5
pairs :
2 and 3

e.g 3:

4
2 2 3 1
4
pairs :
1 and 3
2 and 2

what about no output?
*/