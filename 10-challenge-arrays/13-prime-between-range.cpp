#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t,s,e,i,p,count;
	cin>>t;
	while(t--){
		count = 0;
		cin>>s>>e;
		bool b[e+1];
		memset(b,true,sizeof(b)); // initially all are true 0 to n
		b[0]=b[1]=false;
		for(p=2; p*p<=e; p++){
			if(b[p]){ // prime
			 for(i=p*p; i<=e; i+=p){
				 b[i]=false; // false
			 }
			}
		}
		
	    for(i=s;i<=e;i++){
		    if(b[i]) count++;
	    }
	    cout<<count<<endl;
	} 
	return 0;
}

/*
sieve of eratosthenes to find prime between ranges
*/