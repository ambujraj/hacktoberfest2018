#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int main()
{
    int num, fact, aux;
    vector<int>results;
    results.push_back(1);
    results.push_back(1);
    char c;
    while(true){
    fact = 1;
    cout<<"Enter the number you want to find factorial of: ";
    cin>>num;
    if(num==0){
        fact = 1;
    }
    else if(num==1){
        fact = 1;
    }
    else{
        for(int a=0;a<num;a++){
	    if(results[a]==0){
	       aux = a;
	       break;
	    }
        }
	fact = results[aux-1];
        for (int i=num;i>aux;i--){
            fact = fact*i;
	    results.push_back(fact);
        }
	
    }
    cout<<"Factorial of "<<num<<" is: "<<fact<<endl;
    cout<<"Do You Want to Enter another number?(y/n): ";
    cin>>c;
    if(c=='n' || c=='N'){
        exit(0);
    }
    else{
        continue;
    }
    }
}
