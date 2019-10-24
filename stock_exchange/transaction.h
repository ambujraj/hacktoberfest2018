class Transaction
{
	map< string, Stock* > mp;

	public:
		void addSellTransaction(ll order_id, string timestamp, string stock_str, string type, ll quantity, double price)
		{	
			Stock* stock=NULL;

			if(mp.find(stock_str)!=mp.end())
				stock = mp[stock_str];
			else
			{
				stock = new Stock(stock_str);
				mp[stock_str] = stock;
			}

			if(type=="Sell")
				stock->addSellOrder(order_id, timestamp, quantity, price);

		}

		void processBuyTransaction(ll order_id, string timestamp, string stock_str, string type, ll quantity, double price)
		{
			if(mp.find(stock_str)==mp.end())
				return;

			Stock* stock = mp[stock_str];

			stock->processBuyTransaction(order_id, timestamp, quantity, price);
		}
};