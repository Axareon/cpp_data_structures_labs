/*************************************************************************
 * Name: Muhammad Rahman                                           CSC 240
 * Date: 02/08/2025                                                Lab # 2
 *************************************************************************
 * Statement: This is an implementation of a templated dynamic list class
 * Specifications: The class has list operations including insertion,
 *                 appending, searching, sorting and operator overloads
 * Input - Takes a length and stores elements of different data types
 * Output - Operations are tested via testmyList.cpp 
 *************************************************************************/

#include <iostream>
#include "myList.hpp"

using namespace std; // introduces namespace std

int main()
{

	char ch[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	float fl[] = {1.2, -9, 7};

	// testing default constructor
	myList<double> L;
	cout << "Testing default constructor. List L is:\n";
	L.print(cout);
	cout << endl
		 << endl;

	// testing append method
	L.append(90.8);
	L.append(123);
	cout << "Testing append method. List L is:\n";
	L.print(cout);
	cout << endl
		 << endl;

	// testing assignment constructor for a character element
	myList<char> l(5, 'd');
	cout << "Testing assignment constructor. List l is:\n";
	l.print(cout);
	cout << endl
		 << endl;

	// testing copy constructor
	myList<char> l2(l);
	cout << "After copy constructor, list l2 is: ";
	l2.print(cout);
	cout << endl
		 << endl;

	// testing assignment constructor for an array of character elements
	myList<char> l3(6, ch);
	cout << "After array assignment constructor, list l3 is: ";
	l3.print(cout);
	cout << endl
		 << endl;

	// testing assignment operator
	l2 = l3;
	cout << "After assignment List l2 contains list l3\n";
	l2.print(cout);
	cout << endl
		 << endl;

	// testing assignment constructor for an array of float elements
	myList<float> f(3, fl);
	cout << "After array assignment constructor, list f is: ";
	f.print(cout);
	cout << endl
		 << endl;

	// testing insert method
	f.insert(78, 2);
	cout << "After insert in location 2, List f is:\n";
	f.print(cout);
	cout << endl
		 << endl;

	// testing += operator with a single element
	myList<float> f2(3, 12);
	f2 += 1000;
	cout << "After f2+=1000, list f2 is:\n";
	f2.print(cout);
	cout << endl
		 << endl;

	// testing += operator with another list
	f2 += f;
	cout << "After f2+=f, list f2 is:\n";
	f2.print(cout);
	cout << endl
		 << endl;

	// testing isIn method
	if (f.isIn(456))
		cout << "element is in \n";
	else
		cout << "not in \n";

	cout << "After sort ascending list f2 is:\n";
	f2.sort('a');
	f2.print(cout);
	cout << endl
		 << endl;

	// Test string type
	cout << "Testing with string type:\n";
	myList<string> strList;
	strList.append("Hello");
	strList.append("World");
	strList.append("!");
	cout << "String list contents: ";
	strList.print(cout);
	cout << endl
		 << endl;

	// Test insert at various positions
	cout << "Testing insert at different positions:\n";
	myList<int> insertTest;
	insertTest.append(1);
	insertTest.append(2);
	insertTest.append(3);
	cout << "Original list: ";
	insertTest.print(cout);
	cout << endl;

	// Insert at beginning (position 1)
	insertTest.insert(0, 1);
	cout << "After insert at beginning: ";
	insertTest.print(cout);
	cout << endl;

    // // Test extra credit operators
    // cout << "Testing extra credit operators:\n";

    // // Test the + operator with single element
    // myList<int> addTest(2, 10);
    // myList<int> result = addTest + 20;
    // cout << "After + operator with single element: " << result << endl;

    // // Test the + operator with two lists
    // myList<int> addTest2(2, 30);
    // result = addTest + addTest2;
    // cout << "After + operator with two lists: " << result << endl << endl;

}
