package july6;

//Push in O(n); Pop and Top in O(1)
public class StackUsingQueues2 {
	
	DynamicQueue dataQueue;
	DynamicQueue helperQueue;
	
	public StackUsingQueues2(int cap) {
		dataQueue = new DynamicQueue(cap);
		helperQueue = new DynamicQueue(cap);
	}
	
	//O(n)
	public void push(int val){
		while(dataQueue.size() > 0){
			helperQueue.enqueue(dataQueue.dequeue());
		}
		
		dataQueue.enqueue(val);

		while(helperQueue.size() > 0){
			dataQueue.enqueue(helperQueue.dequeue());
		}
	}
	
	//O(1)
	public int pop(){
		if(dataQueue.size() == 0){
			System.out.println("Stack underflow!");
			return -1;
		}
		
		return dataQueue.dequeue();
	}
	
	//O(1)
	public int top(){
		if(dataQueue.size() == 0){
			System.out.println("Stack underflow!");
			return -1;
		}
		
		return dataQueue.front();
	}
	
	
	public void display(){
		dataQueue.display();
	}
}
