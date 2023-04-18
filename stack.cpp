#include <iostream>
#include "stack.hpp"

Stack::Stack(int size)
{
	m_capacity = size;
	array = new int[m_capacity];
	m_index = -1;
}

Stack::~Stack()
{
	delete[] array;
}

int Stack::get_size()
{
	return m_index + 1;
}

bool Stack::is_empty()
{
	return m_index == -1;
}

bool Stack::is_full()
{
	return m_index == m_capacity - 1;
}

void Stack::push(int item)
{
      if(is_full())
      {
	      std::cout<<"Stack is full!"<<std::endl;
	      return;
      }
      array[++m_index] = item;
}

int Stack::pop()
{
	if(is_empty())
	{
		std::cout<<"Stack is empty!"<<std::endl;
		return -1;
	}
	return array[m_index--];
}

int Stack::top()
{
	if(is_empty())
	{
		std::cout<<"Stack is empty"<<std::endl;
		return -1;
	}
	return array[m_index];
}


