#include<bits/stdc++.h>
using namespace std;
#define inf 1e8

/*
* This segment tree is used to solve range minimum queries and with single value update
*/

int a[100005]={0},tree[400020]={0};

void buildTree(int node,int left,int right)
{
	if(left>right)
	return;

	if(left==right)
	{
		tree[node]=a[left];
		return;
	}

	int mid=(left+right)/2;

	buildTree(2*node,left,mid);
	buildTree(2*node+1,mid+1,right);

	tree[node]=min(tree[2*node],tree[2*node+1]);

	return;
}

int query(int node,int start,int end,int left,int right)
{
	if(start>right||end<left||end<start)
		return inf;
	if(start>=left&&end<=right)
		return tree[node];
	int mid=(start+end)/2;
	return min(query(2*node,start,mid,left,right),query(2*node+1,mid+1,end,left,right));
}

void update(int node,int start,int end,int idx,int val)
{
	if(start>end)
	return;
	if(start==end)
	{
		a[idx]=val;
		tree[node]=a[idx];
		return ;
	}

	int mid=(start+end)/2;

	if(idx>=start&&idx<=mid)
	{
		update(2*node,start,mid,idx,val);
	}
	else if(idx>mid&&idx<=end)
	{
		update(2*node+1,mid+1,end,idx,val);
	}

	tree[node]=min(tree[2*node],tree[2*node+1]);
}

int main()
{
	
	/*
		Enter the no of elements and the no. of queries
	*/
	int n,q;
	cin >> n >> q;
	
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	
	buildTree(1,0,n-1);

	while(q--)
	{
		char c;
		int l,r;
		cin >> c >> l >> r;
		
		/*
		* if query is of the form q 1 5 then it will find the minimum of the values from 1 to 5
		* else if query is of the form u 5 10 them it will update the value of index 5 to 10
		*/
		if(c=='q')
		{
			cout << query(1,0,n-1,l-1,r-1) << endl;
		}
		else
		{
			update(1,0,n-1,l-1,r);
		}
	}
}
