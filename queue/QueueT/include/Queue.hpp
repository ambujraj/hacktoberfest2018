#ifndef Queue_hpp
#define Queue_hpp

#include "Node.hpp"

template<class T>
class Queue {
    private:
        long size;
        Node<T>* frontPtr;
		Node<T>* backPtr;
    public:
        Queue();
		Queue(Queue<T> &s);
        ~Queue();
        T front();
		T back();
        void push(T item);
        void pop();
        void swap();
		bool empty();
        long getSize();
};

template<class T>
Queue<T>::Queue() {
	frontPtr = nullptr;
	backPtr = nullptr;
	size = 0;
}

template<class T>
Queue<T>::Queue(Queue<T> &q) {
	size = q.getSize();
	while(!q.empty()) {
		push(q.front());
		q.pop();
	}
}

template<class T>
Queue<T>::~Queue() {
	Node<T>* current = new Node<T>(frontPtr); //set current to the top
	Node<T>* last = new Node<T>();
	//while we have not reached the end
	while(current != nullptr) {
		last = current; //set last to the top item
		current = current->getNext(); //move to the next item from the top
		last->setNext(nullptr); //erase the data
		delete last; //release the memory space
	}
}

template<class T>
T Queue<T>::front() { 
	if(!empty()) {
		return frontPtr->getData();
	}
	return T();
}

template<class T>
T Queue<T>::back() {
	if(!empty()) {
		return backPtr->getData(); 
	}
	return T();
}

template<class T>
void Queue<T>::push(T item) {
    Node<T>* newNode = new Node<T>();
	newNode->setData(item); //store the value we were given
    if(frontPtr == nullptr) {
        frontPtr = newNode; //set node to our only existing one
        frontPtr->setNext(nullptr); //make the next one null cause we only have one
		backPtr = frontPtr; //back is front and front is back cause we only have 1 node
    } else if (size == 1) {
		backPtr=newNode; // put the new node in the back
		frontPtr->setNext(backPtr); // link the first node to the 2nd node
	} else {
		backPtr->setNext(newNode); //current node in the back links to the new one being added
		backPtr=newNode; //new node gets placed in the back		
    }
    size++; //we added a node!
}

template<class T>
void Queue<T>::pop() {
    //if there's a node to remove
    if(frontPtr != nullptr) {
        Node<T>* current = new Node<T>(frontPtr); //get our top node
        frontPtr = frontPtr->getNext(); //set our top to the next in line
        current->setNext(nullptr); //erase the values of the top node
        delete current; //free the memory
        size--; //we removed a node!
    }
}

template<class T>
void Queue<T>::swap() {
	//if we have at least 2 nodes, swap the values of current and next
	if(size > 1) {
		T temp = frontPtr->getNext()->getData();
		frontPtr->getNext()->setData(frontPtr->getData());
		frontPtr->setData(temp);
	}
}

template<class T>
bool Queue<T>::empty() { 
	return (frontPtr == nullptr || backPtr == nullptr); 
}

template<class T>
long Queue<T>::getSize() { 
	return size; 
}

#endif
