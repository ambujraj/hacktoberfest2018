#include <stack>
#include <iostream>
using namespace std;
int main()
{
stack<int> st;
int no_of_elements;
cout<<"enter number of elements"<<endl;
cin>>no_of_elements;
for (int i = 0; i < no_of_elements; ++i)
{	int temp;
	cout<<"enter element"<<endl;
	cin>>temp;
	st.push(temp);
}
int data;
cout<<"enter data of element to be searched"<<endl;
cin>>data;
bool flag=false;
for (int i = 0; i < no_of_elements; ++i)
{
	if(st.top()==data){
		flag=true;
		cout<<"element found"<<endl;
		break;
	}
	st.pop();
}
if(!flag){
	cout<<"element not found"<<endl;
}
}