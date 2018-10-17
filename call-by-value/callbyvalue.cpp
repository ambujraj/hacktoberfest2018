#include <iostream>
using namespace std;
int sum(int a, int b)//function declared
{
    int sum = a + b;//initialising sum
    return(sum);
}
int main()
{
    int x=0, y=0, z=0;
    cin>>x>>y;//input x and y
    z=sum(x,y);//assigning the value of sum in z
    cout<<z;
}
