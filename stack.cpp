/*
* stack.cpp
* It provides the implementation of the member functions for the stack class
*/

#include "stack.h"

using namespace std;

void stack::push(char item) throw(bound_err)
{
	bound_err err("Push overflows stack");
	if (isFull())
		throw err;
	LinkedStack.insertAtFront(item);
	top = LinkedStack.getHead();
}

char stack::pop() throw(bound_err)
{
	bound_err err("Pop underflows stack");
	if (isEmpty())
		throw err;
	char data = LinkedStack.deleteAtFront();
	top = LinkedStack.getHead();
	return data;
}

int stack::size() const
{
	return LinkedStack.size();
}


bool stack::isEmpty() const
{
	if (top == NULL)
		return true;
	return false;
}

bool stack::isFull() const
{
	if (this->size() >= STACK_SIZE)
		return true;
	else
		return false;
}

