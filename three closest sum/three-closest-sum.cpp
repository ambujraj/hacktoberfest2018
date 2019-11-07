/* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. */

#include<bits/stdc++.h>
using namespace std;
threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int n=A.size();
    int i=0, j=1, k, final_sum = 1000000;
    for(int i=0; i<n-2; i++){
        int ptr1 = i+1, ptr2 = n-1, target = B;
        while(ptr1 < ptr2){
            int sum = A[i] + A[ptr1] + A[ptr2];
            if(abs(target -  sum) < abs(target - final_sum)){
                final_sum = sum;
            }
            if(sum > target){
                ptr2--;
            }
            else
                ptr1++;
        }
    }
    return final_sum;
}

int main(){
	vector<int> v{2,1,-9,-7,-8,2,-8,2,3,-8};
	cout<<threeSumClosest(v,-1)<<endl;
}
