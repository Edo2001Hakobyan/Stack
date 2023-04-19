#include <iostream>
#include <cassert>
#include "list_stack.hpp"



Node::Node(int data)
{
	this->data = data;
	this->next = nullptr;
}

List::List()
{
	m_first = nullptr;
	m_last = nullptr;
        m_size = 0;
}

int List::get_size()
{
	return m_size;
}

bool List::is_empty()
{
	return m_size == 0;
}

void List::push_back(int data)
{
	Node* new_node = new Node(data);
	if(is_empty())
	{
		m_first = new_node;
	}
	else
	{
		m_last->next = new_node;
	}
	m_last = new_node;
	m_size++;
}

void List::print()
{
	Node* current = m_first;
	while(current != nullptr)
	{
		std::cout<<current->data<<" ";
		current = current->next;
	}
	std::cout<<std::endl;
}

int& List::operator[](int index)
{
	assert(index > 0 || index <= m_size);

        Node* current = m_first;
	for(int i = 0;i < index; i++)
	{
		current = current->next;
	}
	return current->data;
}


void List::pop_back()
{
	if(is_empty())
	{
		return;
	}

	if(m_size == 1)
	{
		delete m_first;
		m_first = nullptr;
		m_last = nullptr;
		m_size = 0;
		return;
	}

	Node* current = m_first;
	while(current->next != m_last)
	{
            current = current->next;
	}

	delete m_last;
	m_last = current;
	m_last->next = nullptr;
	m_size--;
}

void List::insert(int index,int value)
{
	
	assert(index > 0 || index < m_size);

	Node* new_node = new Node(value);

	if(is_empty())
	{
		m_first = new_node;
		m_last = new_node;
	}

	else if(index == 0)
	{
		new_node->next = m_first;
		m_first = new_node;
	}

	else
	{
		Node* current = m_first;
		for(int i = 0; i < index-1; i++)
		{
			current = current->next;
		}
		new_node->next = current->next;
	        current->next = new_node;	
	}
	m_size++;
}

void List::remove_value(int value)
{
	if(is_empty())
	{
		return;
	}

	if(m_first->data == value)
	{
		Node* old_node = m_first;
		m_first = m_first->next;
		delete old_node;
		return;
	}

	Node* current = m_first;
	while(current->next != nullptr && current->next->data != value)
	{
		current = current->next;
	}

	if(current->next != nullptr)
	{
		Node* old_node = current->next;
		current->next = current->next->next;
		delete old_node;
	}
}

void List::remove_index(int index)
{
	assert(index >= 0 &&  index < m_size);

	if (index == 0)
	{
		Node* old_node = m_first;
		m_first = m_first->next;
		delete old_node;
		return;
	}

	Node* current = m_first;
	for(int i = 0; i < index-1; i++)
	{
		current = current->next;
	}

	Node* old_node = current->next;
	current->next = current->next->next;
	delete old_node;

	if(index == m_size - 1)
	{
		m_last = current;
	}
}

List::List(const List& other)
{ 
	std::cout<<"Copy constructor"<<std::endl;	
	m_first = nullptr;
	m_last = nullptr;
	Node* current_other = other.m_first;
	while(current_other != nullptr)
	{
		push_back(current_other->data);
		current_other = current_other->next;
	}
}

	/*
{
	std::cout<<"Copy constructor"<<std::endl;
	m_first = nullptr;
	m_last = nullptr;
	Node* current_other = other.m_first;
	Node* prev_new = nullptr;
	while (current_other != nullptr)
	{
		Node* new_node = new Node(current_other->data);
		if(prev_new == nullptr)
		{
			m_first = new_node;
		}
		else
		{
			prev_new->next = new_node;
		}
		prev_new = new_node;
		current_other = current_other->next;
	}
	m_last = prev_new;
}
      */

List::~List()
{
	Node* current = m_first;
	while (current != nullptr)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
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
