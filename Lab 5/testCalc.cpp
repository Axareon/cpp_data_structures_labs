/*************************************************************************
* Name: Muhammad Rahman 										CSC 240
* Date: 3/2/25													Lab # 5
*************************************************************************
* Statement: This is an implementation of a calculator with stacks.
* Specifications: Uses a linked list set to perform calcutations
* Input - myCalc takes string equation inputs.
* Output - Uses testCalc.cpp to test myCalc.hpp
*************************************************************************/

#include <iostream>
#include "myCalc.hpp"
#include "myLinkedList.hpp"
#include "myStack.hpp"

using namespace std;  //introduces namespace std

int main()
{	
	
	string theInput1 = "5/2=";
	string theInput = "2+4*6/5=";
	string theInput2 = "11/3+100-2*5/12-18=";
	string theInput3 = "244+54*65=";
	string theInput4 = "(10+3)*(51/2)/(30-4)=";
	
	double theValue;
	
	myCalc c(theInput1);
	
	cout << "input string is " << c.getInput() << endl;
	cout << "post fix input is " << c.postFixInput() << endl;
	theValue = c.evaluate();
	cout << "Value is " << theValue << endl << endl;
	
	c.resetInput(theInput);
	cout << "input string is " << c.getInput() << endl;
	cout << "post fix input is " << c.postFixInput() << endl;
	theValue = c.evaluate();
	cout << "Value is " << theValue << endl << endl;
	
	c.resetInput(theInput2);
	cout << "input string is " << c.getInput() << endl;
	cout << "post fix input is " << c.postFixInput() << endl;
	theValue = c.evaluate();
	cout << "Value is " << theValue << endl << endl;
	
	c.resetInput(theInput3);
	cout << "input string is " << c.getInput() << endl;
	cout << "post fix input is " << c.postFixInput() << endl;
	theValue = c.evaluate();
	cout << "Value is " << theValue << endl << endl;
	
	c.resetInput(theInput4);
	cout << "input string is " << c.getInput() << endl;
	cout << "post fix input is " << c.postFixInput() << endl;
	theValue = c.evaluate();
	cout << "Value is " << theValue << endl << endl;

}

