/*************************************************************************
* Name: Muhammad Rahman 										CSC 240
* Date: 3/2/25													Lab # 5
*************************************************************************
* Statement: This is an implementation of a calculator with stacks.
* Specifications: Uses a linked list set to perform calcutations
* Input - myCalc takes string equation inputs.
* Output - Uses testCalc.cpp to test myCalc.hpp
*************************************************************************/

#ifndef MYCALC_H_
#define MYCALC_H_

#include <iostream>
#include <cstdlib>
#include <cctype>
#include "myStack.hpp"

using namespace std;

// LAB 5 STUDENT FILE

// a trivial calculator class that evaluates strings containing only =,-,*,/ and integers
// It is assumed that the original input string is in infix notation

// For 10% extra credit on this project allow for the parenthesis grouping symbols (,). For example (5+7)*(3-4)=-12

class myCalc
{
private:
	myStack<char> theStack;
	string input; // assume the string will only contain integers and
				  // the math operations +,-,*,/ and the string
				  // will be in infix notation, for example 2+3*5=
				  // also assume each expression ends with the = symbol

public:
	//*****create any other constructors you feel are needed******

	myCalc(string &str) { input = str; }
	// assignment constructor that initializes input to the value str

	string getInput() { return input; }

	void resetInput(string &str) { input = str; }
	// resets input
	// Postcondition: input is equal to str

	string postFixInput();
	// returns input string as post fix notation
	// Postcondition: Assuming the input string is a valid infix expression,
	// the post fix expression of input is returned

	double evaluate();
	// evaluates the value of the input string
	// Postcondition: Assuming the input string is a valid infix expression,
	// the value of the math expression is returned
};

string myCalc::postFixInput()
{
	string result = "";
	myStack<char> operatorStack;

	for (size_t i = 0; i < input.length(); i++)
	{
		char current = input[i];

		// If curr is a digit, add it to result
		if (isdigit(current))
		{
			// Handle multi-digit numbers
			string numStr = "";
			while (i < input.length() && isdigit(input[i]))
			{
				numStr += input[i];
				i++;
			}
			i--; // Adjust for loop increment
			result += numStr + " ";
		}
		// If curr is '(', push it to stack
		else if (current == '(')
		{
			operatorStack.push(current);
		}
		// If curr is ')', pop all operators until '(' is found
		else if (current == ')')
		{
			while (!operatorStack.isEmpty() && operatorStack.getTop() != '(')
			{
				result += operatorStack.getTop();
				result += " ";
				operatorStack.pop();
			}

			// Remove '(' from stack
			if (!operatorStack.isEmpty() && operatorStack.getTop() == '(')
			{
				operatorStack.pop();
			}
		}
		// If curr is an operator
		else if (current == '+' || current == '-' || current == '*' || current == '/' || current == '=')
		{
			// Get precedence of current operator
			int currentPrecedence = 0;
			if (current == '+' || current == '-')
				currentPrecedence = 1;
			else if (current == '*' || current == '/')
				currentPrecedence = 2;
			// '=' has lowest precedence

			// Pop operators with higher or equal precedence from stack
			while (!operatorStack.isEmpty() && operatorStack.getTop() != '(')
			{
				char topOp = operatorStack.getTop();
				int topPrecedence = 0;
				if (topOp == '+' || topOp == '-')
					topPrecedence = 1;
				else if (topOp == '*' || topOp == '/')
					topPrecedence = 2;

				if (topPrecedence >= currentPrecedence)
				{
					result += topOp;
					result += " ";
					operatorStack.pop();
				}
				else
				{
					break;
				}
			}

			// Push current operator to stack if not '='
			if (current != '=')
			{
				operatorStack.push(current);
			}
		}
	}

	// Pop remaining operators from stack
	while (!operatorStack.isEmpty())
	{
		result += operatorStack.getTop();
		result += " ";
		operatorStack.pop();
	}

	return result;
}

double myCalc::evaluate()
{
	// Infix to postfix
	string postfix = postFixInput();
	myStack<double> valueStack;

	// Parse postfix
	string token = "";
	for (size_t i = 0; i < postfix.length(); i++)
	{
		char current = postfix[i];

		if (current == ' ')
		{
			if (!token.empty())
			{
				// If token is an operator
				if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
				{
					if (valueStack.getCount() < 2)
					{
						// Error handling: not enough operands
						throw runtime_error("Invalid expression: not enough operands");
					}

					double operand2 = valueStack.getTop();
					valueStack.pop();

					double operand1 = valueStack.getTop();
					valueStack.pop();

					// Perform operation
					double result = 0;
					switch (token[0])
					{
					case '+':
						result = operand1 + operand2;
						break;
					case '-':
						result = operand1 - operand2;
						break;
					case '*':
						result = operand1 * operand2;
						break;
					case '/':
						if (operand2 != 0) // Stop div by 0
							result = operand1 / operand2;
						else
							throw runtime_error("Division by 0");
						break;
					}

					// Push result back to stack
					valueStack.push(result);
				}
				// If token is a number
				else if (!token.empty())
				{
					// Convert string to double
					double value = atof(token.c_str());
					valueStack.push(value);
				}

				token = ""; // Reset token
			}
		}
		else
		{
			token += current;
		}
	}

	// Process last token if applicable
	if (!token.empty())
	{
		if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
		{
			double operand2 = valueStack.getTop();
			valueStack.pop();

			double operand1 = valueStack.getTop();
			valueStack.pop();

			// Perform operation
			double result = 0;
			switch (token[0])
			{
			case '+':
				result = operand1 + operand2;
				break;
			case '-':
				result = operand1 - operand2;
				break;
			case '*':
				result = operand1 * operand2;
				break;
			case '/':
				if (operand2 != 0)
					result = operand1 / operand2;
				else
					throw runtime_error("Division by 0");
				break;
			}

			valueStack.push(result);
		}
		else
		{
			double value = atof(token.c_str());
			valueStack.push(value);
		}
	}

	// Result should be on top
	if (!valueStack.isEmpty())
	{
		return valueStack.getTop();
	}

	return 0; // Default return
}

#endif /* MYCALC_H_ */
