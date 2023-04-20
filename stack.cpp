#include <iostream>
#include <cassert>
#include "stack.hpp"

Node::Node(int data)
{
	this->data = data;
	this->next = nullptr;
}

Stack::Stack()
{
	m_top = nullptr;
	m_size = 0;
}

Stack::~Stack()
{
	while(m_top)
	{
		Node* temp = m_top;
		m_top = m_top->next;
		delete temp;
	}
}

bool Stack::is_empty()
{
	return m_top == nullptr;
}

int Stack::get_size()
{
	return m_size;
}

void Stack::push(int value)
{
	Node* new_node = new Node(value);
	new_node->next = m_top;
	m_top = new_node;
	m_size++;
}

int Stack::pop()
{
	if(is_empty())
	{
		std::cout<<"Stack is empty!"<<std::endl;
		return -1;
	}
	int value = m_top->data;
	Node* temp = m_top;
	m_top = m_top->next;
	delete temp;
	m_size--;
	return value;
}

int Stack::top()
{
	if(is_empty())
	{
		std::cout<<"Stack is empty!"<<std::endl;
		return -1;
	}
	return m_top->data;
}
