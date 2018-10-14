#include<iostream>
using namespace std;
struct nodes {
	int data;
	nodes* next;
};
class LinkList {
	private:
		nodes* first;
	public:
		LinkList() { first = NULL; }
		void AddData(int d);
		void Display();
};
void LinkList::AddData(int d) {
	nodes* newlink = new nodes;
	newlink->data = d;
	newlink->next = first;
	first = newlink;
}
void LinkList::Display() {
	nodes* current = first;
	while(current != NULL) {
		cout<<current->data<<endl;
		current = current->next;
	}
}
int main() {
	LinkList l;
	l.AddData(34);
	l.AddData(45);
	l.AddData(65);
	l.AddData(66);
	l.Display();
	return 0;
}
