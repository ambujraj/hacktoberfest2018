#include <bits/stdc++.h>
using namespace std;
void Heapify(vector<int>C,int i,int k){
	int largest=i;
	int lchild=2*i;
	int rchild=2*i+1;

	if(lchild<k && C[lchild]>C[largest])
		largest=lchild;

	if(rchild<k && C[rchild]>C[largest])
		largest=rchild;

	if(largest!=i){
		swap(C[i],C[largest]);
		Heapify(C,largest,k);
	}

}

void BuildMaxHeap(vector<int>C,int k){
	for(int i=k/2;i>=0;k--){
		Heapify(C,i,k);
	}
}

int main(int argc, char const *argv[])
{
	vector<int>C;
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int value;
		cin>>value;
		C.push_back(value);
	}

	BuildMaxHeap(C,C.size());
	int size=C.size();
	for(int i=C.size()-1;i>=1;i--){
		swap(C[0],C[i]);
		size--;
		Heapify(C,0,size);
	}
	for(int i=0;i<C.size();i++)
		cout<<C[i]<<" ";
	return 0;
}