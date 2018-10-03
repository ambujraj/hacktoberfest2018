#include <iostream>
#include "math.h"

using namespace std;

bool isPrime(int number);

int main(){
    int number;

    cin >> number;

    if(isPrime(number)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }

    return 0;
}


bool isPrime(int number){
    if(number == 1){return true;}

    int sqrtNumber; 
    sqrtNumber = sqrt(number);

    for(int i = 1; i <= sqrtNumber; i++){
        if(isPrime(i)){
            if (number % i == 0 && i != 1){
                return false; 
            }
        }
    }
    return true;
}
