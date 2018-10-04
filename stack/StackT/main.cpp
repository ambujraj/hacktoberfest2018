#include <iostream>
#include "Stack.h"

int main(){
	Stack<int> s;
    for(int i = 1; i < 8; i++){
        s.push(i);
    }
    long l = 0;
    while(!s.empty()){
        l = s.getSize();
        std::cout << "value: " << s.top() 
            << " size: " << l << '\n';
        s.pop();
    }
	for(int i = 2; i < 6; i++){
        s.push(i);
    }
	std::cout << std::endl;
	while(!s.empty()){
		s.swap();
        l = s.getSize();
        std::cout << "value: " << s.top() 
            << " size: " << l << '\n';
        s.pop();
    }
	std::cout << std::endl;
    return 0;
}
