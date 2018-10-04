#ifndef Stack_hpp
#define Stack_hpp

#include "Node.hpp"

template<class T>
class Stack {
    private:
		long size;
		Node<T>* nodePtr;
    public:
		Stack();
		Stack(Stack<T> &s);
		~Stack();
		T top();
		void push(T item);
		void pop();
		void swap();
		bool empty();
		long getSize();
};

template<class T>
Stack<T>::Stack() { 
	nodePtr = nullptr;
	size = 0; 
}

template<class T>
Stack<T>::Stack(Stack<T> &s) {
	size = s.getSize();
	T t[size];
	//store the stack into an array of same size, from bottom to top
	for(unsigned i = 0; i < size; i++) {
		t[i] = s.top();
		s.pop();
	}
	//store the values from array into our stack, from top to bottom
	for(unsigned i = size-1; i >= 0; i--) {
		push(t[i]);
	}
}

template<class T>
Stack<T>::~Stack() {
	Node<T>* current = new Node<T>(nodePtr); //set current to the top
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
void Stack<T>::push(T item) {
    Node<T>* newNode = new Node<T>();
	newNode->setData(item); //store the value we were given
    if(nodePtr == nullptr) {
        nodePtr = newNode; //set node to our only existing one
        nodePtr->setNext(nullptr); //make the next one null cause we only have one
    } else {
        newNode->setNext(nodePtr); //make the next pointer set to our current position
        nodePtr = newNode; //move our current to the newest node
    }
    size++; //we added a node!
}

template<class T>
void Stack<T>::pop() {
    //if there's a node to remove
    if(nodePtr != nullptr) {
        Node<T>* current = new Node<T>(nodePtr); //get our top node
        nodePtr = nodePtr->getNext(); //set our top to the next in line
        current->setNext(nullptr); //erase the values of the top node
        delete current; //free the memory
        size--; //we removed a node!
    }
}

template<class T>
void Stack<T>::swap() {
	//if we have at least 2 nodes, swap the values of current and next
	if(size > 1) {
		T temp = nodePtr->getNext()->getData();
		nodePtr->getNext()->setData(nodePtr->getData());
		nodePtr->setData(temp);
	}
}

template<class T>
T Stack<T>::top() {
	return nodePtr->getData();
}

template<class T>
bool Stack<T>::empty() {
	return (nodePtr == nullptr);
}

template<class T>
long Stack<T>::getSize() {
	return size;
}

#endif
