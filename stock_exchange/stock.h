class Stock
{	
	string id;
	SellOrder *head = NULL, *lastSellOrder = NULL;

	public:
		Stock(string stock_str)
		{	
			id = stock_str;
		}

		void addSellOrder(ll order_id, string timestamp, ll quantity, double price)
		{	
			SellOrder* order = new SellOrder(order_id, timestamp, quantity, price);
			
			if(lastSellOrder==NULL)
				head = lastSellOrder = order;
			else
			{
				lastSellOrder->pushOrder(order);
				lastSellOrder = order;
			}
		}

		void processBuyTransaction(ll order_id, string timestamp, double quantity, double price)
		{	
			if(head==NULL)
				return;

			SellOrder *order=head;

			set< pair<double,ll> > ss;
			map< pair<double,ll>,double> mp;

			ll time_index = computeTime(timestamp);

			while(order!=NULL)
			{	

				ll in = computeTime(order->getTimeStamp());
				double order_price = order->getPrice();

				if( in < time_index)
				{
					if( order_price <= price)	
					{	
						ss.insert( _mp(order_price, in) );
						mp[_mp(order_price, in)]+=order->getQuantity();
					}
				}
				else
					break;

				order = order->getNextOrder();
			}

			pair<double,ll> top;
			while(quantity>0 && !ss.empty())
			{	
				order = head;
				top = *ss.begin();

				if(mp[top]==0)
				{
					ss.erase(top);
					continue;
				}

				double in_use = min(mp[top],quantity);
				quantity -= in_use;
				double in_use_per_stock = (double)in_use/mp[top];

				while(order!=NULL)
				{
					ll in = computeTime(order->getTimeStamp());
					double order_price = order->getPrice();

					if( in < time_index)
					{
						if( order_price == top.ff && in == top.ss)	
						{	
							double quantity_used = order->getQuantity()*in_use_per_stock;
							if(quantity_used!=0)
								cout<<order->getOrderId()<<" "<<order_id<<" "<<quantity_used<<" "<<order->getPrice()<<"\n";
							order->useQuantity(quantity_used);
						}
					}
					else
						break;

					order = order->getNextOrder();
				}

				ss.erase(top);
			}
		}

};