#include<bits/stdc++.h>
using namespace std;

int maxPalin(string s)
{
	int n=s.size();
	bool tab[n][n];
	memset(tab,0,sizeof(tab));

	for(int i=0;i<n;i++)
		tab[i][i]=true;

	int mL=1,start=0;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			tab[i][i+1] = true;
			start =i;
			mL = 2;
		}
	}
	for(int k=3;k<=n;k++)
	{
		for(int i=0;i<n-k+1;i++)
		{
			int j = i+k-1;
			if(tab[i+1][j-1] && s[i] ==s[j])
			{
				tab[i][j] = true;
				if(k>mL)
					{
					start = i;
					mL=k;
				}
			}
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++)
//			cout<<tab[i][j];
//		cout<<endl;
	}
	return mL;
}
int main()
{
  string s;
  getline(cin,s);
	cout<<maxPalin(s);
}
