/*************************************************************************
* Name: Muhammad Rahman                                           CSC 240
* Date: 2/23/25                                                   Lab # 4
*************************************************************************
* Statement: This is an implementation of a linked list with appropriate methods.
* Specifications: Uses nodes with data and pointers and methods with iteration
* Input - Takes node inputs with data to fill out linked list.
* Output - Tested with testmyStack.cpp
*************************************************************************/

#include <iostream>
#include "myLinkedList.hpp"
#include "myStack.hpp"

using namespace std;  //introduces namespace std

int main()
{	
	myStack<int> s;
	s.print(cout);
	cout << endl;
	
	cout << "After push of " << 10 << " stack is \n";
	s.push(10);
	s.print(cout);
	cout << "Count is " << s.getCount() << endl;
	cout << endl;
	
	cout << "After push of " << 25 << " stack is \n";
	s.push(25);
	s.print(cout);
	cout << "Count is " << s.getCount() << endl;
	cout << endl;
	
	cout << "After push of " << 100 << " stack is \n";
	s.push(100);
	s.print(cout);
	cout << "Count is " << s.getCount() << endl;
	cout << endl;
	
	cout << endl;
	
	cout << "top is " << s.getTop() << endl;
	
	s.pop();
	cout << "after pop stack is \n";
	s.print(cout);
	cout << "Count is " << s.getCount() << endl;
	cout << endl;
	
}

