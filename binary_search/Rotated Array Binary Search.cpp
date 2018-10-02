// similar questions smallest number, no. of elements rotated etc...
#include <bits/stdc++.h>
using namespace std;

int get_pivot(vector<int> v, int beg, int end) {
	// cout<<beg<<" "<<end<<endl;
	if (beg > end)
		return -1;

	int mid = (beg + ((end - beg)/2));
	if (v[beg] > v[end] && v[end] < v[mid])
		return get_pivot(v, mid+1, end);
	else if (v[beg] > v[end] && v[end] > v[mid])
		return get_pivot(v, beg, mid-1);
	else if (v[beg] <= v[end])
		return beg;

}

int bsearch(vector<int> v, int beg, int end, int ele) {
	if (beg > end)
		return -1;

	int mid = (beg + ((end - beg)/2));
	if (v[mid] < ele)
		return bsearch(v, mid+1, end, ele);
	else if (v[mid] > ele)
		return bsearch(v, beg, mid-1, ele);
	else
		return mid;
}

int solve(vector<int> v, int beg, int end, int ele) {
	// cout<<beg<<" "<<end<<endl;
	if (beg > end)
		return -1;

	int mid = (beg + ((end - beg)/2));
	if (ele == v[mid])
		return mid;
	
	// pivot in left
	if (v[mid] < v[beg]) {
		if (ele > v[mid] && ele <= v[end])
			return solve(v, mid+1, end, ele);
		else
			return solve(v, beg, mid-1, ele);
	}
	// pivot in right
	if (ele >= v[beg] && ele < v[mid])
		return solve(v, beg, mid-1, ele);
	return solve(v, mid+1, end, ele);
}

int main() {
	int n, x;
	cin>>n;
	vector <int> v(n);

    // input
	for (int i = 0; i < n; ++i)
		cin>>v[i];
	cin>>x;

	// 3*O(log n) solution
	int pivot = get_pivot(v, 0, v.size()-1);
	cout<<bsearch(v, 0, pivot-1, x) + bsearch(v, pivot, v.size()-1, x) + 1<<endl;
	
	// O(log n) solution
	cout<<solve(v, 0, v.size()-1, x)<<endl;
	return 0;
}