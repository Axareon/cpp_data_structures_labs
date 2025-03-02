/*************************************************************************
* Name: Muhammad Rahman                                           CSC 240
* Date: 2/23/25                                                   Lab # 4
*************************************************************************
* Statement: This is an implementation of a linked list with appropriate methods.
* Specifications: Uses nodes with data and pointers and methods with iteration
* Input - Takes node inputs with data to fill out linked list.
* Output - Tested with testmyStack.cpp
*************************************************************************/

#ifndef MYSTACK_H_
#define MYSTACK_H_

#include <iostream>
#include "myLinkedList.hpp"

using namespace std;

// LAB 4 STUDENT FILE

// template class that implements a stack data structure using
// a linked list (myLinkedList).

// since myStack inherits from myLinkedList, the implementation of myStack should be
// quite trivial. For example, the push method can call the addFirst method from
// myLinkedList
template <class type>
class myStack : public myLinkedList<type>
{

// We're basically stealing myLinkedList's methods and putting them here with myLinkedList<type>::theMethod()
public:
	// create any constructors you feel are needed

	// default constructor
	myStack() { myLinkedList<type>::setDataMembers(); }

	type getTop()
	{
		// returns the top element of the stack
		// Postcondition: Assuming the stack is not empty, the top element
		// of the stack is returned
		return myLinkedList<type>::getTop();
	};

	void pop()
	{
		// removes the top element of the stack
		// Postcondition: Assuming the stack is not empty, the top element
		// of the stack is removed from stack
		this->myLinkedList<type>::pop();
	};

	void push(const type &theItem)
	{
		// adds a new item to the stack
		// Postcondition: The parameter theItem is added to the top of the stack
		this->myLinkedList<type>::push(theItem);
	};

	int getCount()
	{
		return myLinkedList<type>::getCount();
	}

	void print(ostream &outStream)
	{
		this->myLinkedList<type>::print(outStream);
	}
};

#endif /* MYSTACK_H_ */
