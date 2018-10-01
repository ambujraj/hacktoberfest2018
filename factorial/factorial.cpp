#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;


int factorial(int n) 
{ 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 


int main()
{
    int num, fact, aux;
    vector<int>results;
    results.push_back(1);
    results.push_back(1);
    char c;
    while(true){
		fact = 1;
		cout << "Enter the number you want to find factorial of: ";
		cin >> num;
		factorial(num);
		
		//optimised and short code of factorial
		cout <<"Factorial of "<< num <<" is: "<< fact << endl;
		cout <<"Do You Want to Enter another number?(y/n): ";
		cin>>c;
		if(c=='n' || c=='N')
		{
			exit(0);
		}
		else
		{
			continue;
		}
	}
return 0;

}
