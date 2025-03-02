/*************************************************************************
* Name: Muhammad Rahman                                           CSC 240
* Date: 2/2/2025                                                  Lab #1
*************************************************************************
* Statement: This program will test the swapIt, isDigitString, reverse, 
printAddresses, and printASCII functions.
* Specifications:
* Input - The user will input a positive integer and a string.
* Output - The program will output the swapped values, the reversed string, 
the addresses of each memory location of the dynamic array, and the ASCII 
decimal code for each character in the string.	
*************************************************************************/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;  

//LAB 1 STUDENT FILE

//Postcondition: The value in parameter a contains the value that was in parameter b and
//the value of parameter b contains the value that was in parameter a
template <class type> void swapIt(type &a, type &b);

//Postcondition: Returns true if all characters in the string (dynamic character array)
//are a numerical digit (0,1,2,3,4,5,6,7,8,9). Otherwise the function returns false
bool isDigitString(const char *);

//Postcondition: Reverses the order of the characters in the 
//string (dynamic character array)
void reverse(char *);

//Postcondition: Prints the addresses of each memory location of the dynamic array 
template <class type> void printAddresses(type *, int);

//Postcondition: Prints the ASCII decimal code for each character in the 
//string (dynamic character array) 
void printASCII(char *);

//prewritten test drivers for functions
void test_isDigitString();
void test_reverse(char *);

int main()
{
	//you may want to comment out certain code below so you can do 
	//more specific testing or add your own testing

	//testing swapIt function with integers
	int x = 2, y = 8;
	cout << "Before swap x = " << x << " and y = " << y << endl;
	swapIt(x,y);
	cout << "After swap x = " << x << " and y = " << y << endl;
	
	//testing swapIt function with booleans
	bool a = true, b = false;
	cout << boolalpha;
	cout << "Before swap x = " << a << " and y = " << b << endl;
	swapIt(a,b);
	cout << "After swap x = " << a << " and y = " << b << endl;

	//test if isDigitString function is working properly
	test_isDigitString();
	cout << endl;
	
	//test if reverse function is working properly
	char str[] = "This is a test";
	test_reverse(str);
	cout << endl;
	
	//test if printAddresses function is working properly
	printAddresses(str, strlen(str));
	cout << endl;
	
	//test if printASCII function is working properly
	printASCII(str);
	cout << endl;	
}

//Postcondition: The value in parameter a contains the value that was in parameter b and
//the value of parameter b contains the value that was in parameter a
template <class type>
void swapIt(type &a, type&b)
{
	type temp = a;
    a = b;
    b = temp;
}

//Postcondition: Returns true if all characters in the string (dynamic character array)
//are a numerical digit (0,1,2,3,4,5,6,7,8,9). Otherwise the function returns false
bool isDigitString(const char *theString)
{
    if (theString == nullptr || *theString == '\0')
        return false;
        
    for (int i = 0; theString[i] != '\0'; i++) {
        if (!isdigit(theString[i]))
            return false;
    }
    return true;
}

//Postcondition: Reverses the order of the characters in the 
//string (dynamic character array)
void reverse(char *theString)
{
	int length = strlen(theString);
    for (int i = 0; i < length/2; i++) {
        char temp = theString[i];
        theString[i] = theString[length-1-i];
        theString[length-1-i] = temp;
    }
}

//Postcondition: Prints the addresses of each memory location of the dynamic array 
template <class type> 
void printAddresses(type *item, int n)
{
	// int i; //counter variable for loop
	for (int i = 0; i < n; i++) {
	//In loop, add the descriptive message
		cout << "The address of item[" << i << "]=" << item[i] << " is ";
		cout << (void*)&item[i] << endl;
    }	
	
}

//Postcondition: Prints the ASCII decimal code for each character in the 
//string (dynamic character array) 
void printASCII(char *theString)
{
	// int i; //counter variable for loop
	for (int i = 0; theString[i] != '\0'; i++) {
	//In loop, add the descriptive message
		cout << "The ASCII code for item[" << i << "]=" << theString[i] << " is ";
		cout << (int)theString[i] << endl;
    }
			 
}

void test_isDigitString()
{
	bool tryAgain = false;
	int size;

	cout << "Enter the maximum size for your string.\n";
	cin >> size;
	cin.ignore(80, '\n');
	char *str = new char[size];
	string temp = string(str);
	
	do
	{
		cin.clear();
		cout << "Enter a positive integer.\n";
		getline(cin, temp);
		
		if(isDigitString(temp.c_str()))
		{
			cout << "You have entered the positive integer " << temp << endl;
			tryAgain = false;
		}	
		else
		{	
			cout << "You have entered incorrect data. Please try again.\n\n";
			tryAgain = true;
		}	
		
	}while(tryAgain);
	
	delete str;
}


void test_reverse(char *theString)
{
	reverse(theString);
	cout << "Your string in reverse is: " << theString << endl;
}