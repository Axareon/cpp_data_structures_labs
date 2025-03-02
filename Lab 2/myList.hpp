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

#ifndef MYLIST_H_
#define MYLIST_H_

#include <iostream>
#include <cctype>

using namespace std;

// PROJECT 2 STUDENT FILE

// template class that simulates an ordered list of common elements
// It is assumed that the list will either be empty or completely full
template <class type>
class myList
{
protected:
	int length;	 // the number of elements in the list
	type *items; // dynamic array to store the elements

public:
	~myList()
	{
		// destructor for memory cleanup
		// Postcondition: Deallocates the memory occupied by the items array
		delete[] items;
	}

	myList()
	{
		// default constructor
		// Postcondition: creates items array of size 0 and sets size to zero
		length = 0;
		items = nullptr;
	}

	myList(int n, type t)
	{
		// assignment constructor
		// Postcondition: creates items array of size n. Each element in the list
		// is assigned the value of type t, sets length to n
		length = n;
		items = new type[n];
		for (int i = 0; i < n; i++)
		{
			items[i] = t;
		}
	}

	myList(int n, type *anArray)
	{
		// assignment constructor
		// Postcondition: copies contents of anArray parameter into items array
		// sets length to n
		length = n;
		items = new type[n];
		for (int i = 0; i < n; i++)
		{
			items[i] = anArray[i];
		}
	}

	myList(const myList &otherList)
	{
		// copy constructor
		// Postcondition: makes a deep copy of the parameter otherList to
		// the calling list
		length = otherList.length;
		items = new type[length];
		for (int i = 0; i < length; i++)
		{
			items[i] = otherList.items[i];
		}
	}

	void print(ostream &outStream)
	{
		// prints the elements of the list using outStream
		// Postcondition: The elements of the list are printed to the
		// output stream each separated by a comma. The last element
		// printed should not have a comma after it
		for (int i = 0; i < length; i++)
		{
			outStream << items[i];
			if (i < length - 1)
			{
				outStream << ", ";
			}
		}
	}

	void append(const type &theItem)
	{
		// assigns the parameter theItem to the end of the list
		// Postcondition: the parameter theItem is the last element in the list
		type *newItems = new type[length + 1];
		for (int i = 0; i < length; i++)
		{
			newItems[i] = items[i];
		}
		newItems[length] = theItem;
		delete[] items;
		items = newItems;
		length++;
	}

	bool isIn(const type &theItem)
	{
		// determines if an element is currently in the list
		// Postcondition: Returns true if the parameter theItem is in the list,
		// otherwise returns false
		for (int i = 0; i < length; i++)
		{
			if (items[i] == theItem)
			{
				return true;
			}
		}
		return false;
	}

	bool insert(const type &theItem, int location)
	{
		// inserts an element into the list
		// Postcondition: inserts the parameter theItem into the list at position
		// determined by the parameter location and then returns true, if the location
		// is greater than the length of the list + 2, then the function returns false
		// LOCATION MEANS COUNTING FROM 1, SO LOCATION 1 MEANS INDEX POSITION 0, ETC..
		if (location > length + 1)
		{
			return false;
		}

		// convert
		int index = location - 1;

		type *newItems = new type[length + 1];

		// add until target
		for (int i = 0; i < index; i++)
		{
			newItems[i] = items[i];
		}

		newItems[index] = theItem;

		// add after target
		for (int i = index; i < length; i++)
		{
			newItems[i + 1] = items[i];
		}

		delete[] items;
		items = newItems;
		length++;
		return true;
	}

	void sort(char ch)
	{
		// Assuming the list contains numbers, characters, or strings this functions
		// sorts the elements in the list, where type is either 'A','a'
		// for ascending, or 'D','d' for descending
		// Choose any sorting algorithm of your choice
		// Postcondition: sorts the elements in the list

		// bubblesort
		bool ascending = (ch == 'A' || ch == 'a');

		for (int i = 0; i < length - 1; i++)
		{
			for (int j = 0; j < length - i - 1; j++)
			{
				if (ascending)
				{
					if (items[j] > items[j + 1])
					{
						type temp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = temp;
					}
				}
				else
				{
					if (items[j] < items[j + 1])
					{
						type temp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = temp;
					}
				}
			}
		}
	}

	// OVERLOADED OPERATORS
	myList &operator=(const myList &rhs)
	{
		// overloading of the assignment operator to allow for list to list assignment
		if (this != &rhs)
		{
			delete[] items;
			length = rhs.length;
			items = new type[length];
			for (int i = 0; i < length; i++)
			{
				items[i] = rhs.items[i];
			}
		}
		return *this;
	}

	myList &operator+=(const type &t)
	{
		// overloading of the addition_equal operator that adds the parameter t
		// to the end of the list
		append(t);
		return *this;
	}

	myList &operator+=(const myList &rhs)
	{
		// overloading of the addition_equal operator that adds another list
		// to the end of the list

		type *newItems = new type[length + rhs.length];

		for (int i = 0; i < length; i++)
		{
			newItems[i] = items[i];
		}

		for (int i = 0; i < rhs.length; i++)
		{
			newItems[length + i] = rhs.items[i];
		}

		delete[] items;
		items = newItems;
		length += rhs.length;
		return *this;
	}

	/*
		FOR 10% EXTRA CREDIT ON THIS PROJECT GRADE, OVERLOAD THE FOLLOWING OPERATORS
		AS NON-MEMBER FUNCTIONS
		(1) << (insertion)
		(2) + (addition) that adds one element to a list
		(3) + (addition) that adds two lists

		HINT: to overload both addition operators as stated above use the member
			  functions +=
		KEEP IN MIND THAT THE SYNTAX GETS TRICKY WHEN WRITING NON-MEMBER FUNCTIONS
		FOR TEMPLATE CLASSES

		See example prototypes below
	*/

	// friend ostream& operator<< (ostream& outStream, const myList<type>& theList){}
	// friend myList& operator+ (myList<type> &lhs, const type& t){}
	// friend myList& operator+ (myList<type> &lhs, const myList<type>& rhs){}

	// template <class T>
	// friend ostream &operator<<(ostream &outStream, const myList<T> &theList)
	// {
	// 	for (int i = 0; i < theList.length; i++)
	// 	{
	// 		outStream << theList.items[i];
	// 		if (i < theList.length - 1)
	// 		{
	// 			outStream << ", ";
	// 		}
	// 	}
	// 	return outStream;
	// }

	// template <class T>
	// friend myList<T> operator+(myList<T> lhs, const T &t)
	// {
	// 	lhs += t;
	// 	return lhs;
	// }

	// template <class T>
	// friend myList<T> operator+(myList<T> lhs, const myList<T> &rhs)
	// {
	// 	lhs += rhs;
	// 	return lhs;
	// }
};


// template <class type>
// myList<type>::~myList()
// {
// 	delete[] items;
// }

// template <class type>
// myList<type>::myList()
// {
// 	length = 0;
// 	items = new type;
// 	items = NULL;
// }

#endif /* MYLIST_H_ */
