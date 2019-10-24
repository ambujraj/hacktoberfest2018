

/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define M(x) (x%MOD + MOD)%MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second
#define s(x) scanf("%lld",&x)

ll mul(ll x,ll y)
{ ll ans=1;

  while(y>0)
  { if(y&1)
	ans=(ans*x)%MOD;
	y/=2;
	x=(x*x)%MOD;
  }

  return ans;
};

/******************************************************************************************************/

ll computeTime(string str)
{
	ll ans = 0,aa;

	aa = (str[0]-'0')*10 + (str[1]-'0');
	ans += aa*60;

	aa = (str[3]-'0')*10 + (str[4]-'0');
	ans += aa;

	return ans;
};

#include "sellorder.h"
#include "stock.h"
#include "transaction.h"

int main()
{	
	fstream file;
	file.open("input.txt");
	// freopen ("output.txt", "w", stdout);
	ll order_id, quantity;
	string timestamp, stock_str, type;
	double price;

	Transaction transact;

	while(file>>order_id>>timestamp>>stock_str>>type>>quantity>>price)
	{	
		// cout<<order_id<<" "<<timestamp<<" "<<stock_str<<" "<<type<<" "<<quantity<<" "<<price<<"\n";

		if(type=="Sell")
			transact.addSellTransaction(order_id, timestamp, stock_str, type, quantity, price);
		else
			transact.processBuyTransaction(order_id, timestamp, stock_str, type, quantity, price);
	}

	return 0;
}