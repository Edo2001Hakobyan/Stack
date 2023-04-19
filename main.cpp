#include <iostream>
#include <cassert>
#include "list_stack.hpp"

int main()
{
	Stack stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	std::cout<<"Top element: "<<stack.top()<<std::endl;
         
        stack.push(4);
	stack.push(5);
	std::cout<<"Size of stack: "<<stack.get_size()<<std::endl;

	stack.pop();
	std::cout<<"Top element: "<<stack.top()<<std::endl;	
	std::cout<<"Size of stack: "<<stack.get_size()<<std::endl;


	return 0;
}
