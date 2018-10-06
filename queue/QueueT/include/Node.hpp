#ifndef Node_hpp
#define Node_hpp

template<class T>
class Node {
	private:
		T data;
		Node* next;
	public:
		Node() { this->next = nullptr; }
		Node(T data) { this->next = nullptr; this->data = data; }
		Node(Node<T>* n) { this->next = n->getNext(); this->data = n->getData(); }
		T getData() { return data; }
		Node<T>* getNext() { return next; }
		void setData(T data) { this->data = data; }
		void setNext(Node<T>* next){ this->next = next; }
};

#endif
