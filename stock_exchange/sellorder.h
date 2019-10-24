class SellOrder
{	
	string timestamp;
	ll order_id;
	double quantity,price;
	SellOrder* nextOrder=NULL;

	public:
		SellOrder(ll _order_id, string _timestamp, double _quantity, double _price)
		{
			timestamp = _timestamp;
			order_id = _order_id;
			quantity = _quantity;
			price = _price;
		}

		void pushOrder(SellOrder *nextSellOrder)
		{
			nextOrder = nextSellOrder;
		}

		SellOrder* getNextOrder()
		{
			return nextOrder;
		}

		string getTimeStamp()
		{
			return timestamp;
		}

		double getPrice()
		{
			return price;
		}

		double getQuantity()
		{
			return quantity;
		}

		ll getOrderId()
		{
			return order_id;
		}

		void useQuantity(double quantity_used)
		{
			quantity-=quantity_used;
		}
};