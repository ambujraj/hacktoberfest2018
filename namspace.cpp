#include<iostream>
using namespace std;
namespace test
{
	class t
	{
		public:
			int a=20;
			t(){
				a=10;
				cout<<a<<endl;
			}
	};
}
namespace test
{
	class t1
	{
		public:
			int b;
			t1(){
				b=20;
				cout<<b<<endl;
			}
	};
}
int main()
{
	test::t o1;
	test:: t1 o2;
}
