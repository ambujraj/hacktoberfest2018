#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int height[n], left_max[n], right_max[n];
    for(int i=0;i<n;i++){
        cin>>height[i];
        left_max[i] = (i>0)? max(left_max[i-1],height[i]): height[i];
    }
    for(int i=n-1;i>=0;i--){
        right_max[i] = (i<n-1)? max(right_max[i+1],height[i]): height[i];
    }
    // output array
    // calculate water
    int water=0;
    for(int i=0;i<n;i++){
        water += min(left_max[i], right_max[i]) -height[i];
    }
    cout<<water<<endl;
    return 0;
}

/*

Note: same problem under 08-array-1.0/08-rainwater-trapping.cpp
Input: 
10
0 2 1 3 0 1 2 1 2 1
Output:
5

*/
