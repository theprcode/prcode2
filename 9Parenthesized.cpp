/*
AIM:
In any language program mostly syntax error occurs due to unbalancing delimiter
such as (),{},[]. 
Write C++ program using stack to check whether given expression is 
well parenthesized or not.

INPUT: 
    1. Infix Expression
	
OUTPUT:
	a) Display out put whether the expression is well parenthesized or not
	

AUTHOR:  Sunil
DATE: 27.09.2024
*/
#include<iostream>
#define MAX 10
using namespace std;

//ADT Stack
class Stack {
	private:
		char S[MAX]; // Stack array
		int top; // pointer to the top element of a stack
	public:
		Stack() {
			top = -1; // Stack empty means top points to an invalid location
		}

		// check if stack is empty
		bool isStackEmpty() {
			return top == -1;
		}

		// check if stack is full
		bool isStackFull() {
			return top == MAX - 1;
		}

		// Add element in stack 'Push Operation'
		void push(char token) {
			if (!isStackFull())
				S[++top] = token;
			else
				cout << "\nStack is full!!";
		}

		// Remove element from stack 'Pop Operation'
		char pop() {
			if (!isStackEmpty()) {
				return S[top--];
			} else {
				cout << "\nStack is Empty!!";
				return '\0';
			}
		}

		// Display stack contents
		void displayStack() {
			if (!isStackEmpty()) {
				for (int i = top; i >= 0; i--)
					cout << "\n" << S[i];
			} else {
				cout << "\nStack Empty!!";
			}
		}
};

// Implementation class
class BalancedExpression {
	private:
		char E[20]; // an array to store an infix expression
		Stack stk;
	public:
		void readExpression() {
			cin >> E;
		}

		void displayExpression() {
			cout << "\nThe input infix expression is: " << E;
		}

		void checkExpression() {
			bool invalid = false;
			int i = 0;
			while (E[i] != '\0') {
				if (E[i] == '(' || E[i] == '{' || E[i] == '[')
					stk.push(E[i]);
				else if (E[i] == ')') {
					if (stk.pop() != '(') {
						invalid = true;
						break;
					}
				} else if (E[i] == '}') {
					if (stk.pop() != '{') {
						invalid = true;
						break;
					}
				} else if (E[i] == ']') {
					if (stk.pop() != '[') {
						invalid = true;
						break;
					}
				}
				i++; // go to the next array index of the expression
			} // end while

			if (stk.isStackEmpty() && !invalid)
				cout << "\nThe expression is well parenthesized!";
			else
				cout << "\nThe expression is NOT well parenthesized!";
		} // end function checkExpression
}; // end class

// Driver Code
int main() {
	int choice = 0;
	BalancedExpression obj;
	while (choice != 4) {
		cout << "\n***************WELL FORMED EXPRESSION*****************";
		cout << "\n1. Read Infix Parenthesized Expression";
		cout << "\n2. Display Expression";
		cout << "\n3. Check Expression";
		cout << "\n4. Exit Application";
		cout << "\nWhat is your choice::";
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "\nEnter Infix Parenthesized Expression: ";
				obj.readExpression();
				break;
			case 2:
				obj.displayExpression();
				break;
			case 3:
				obj.checkExpression();
				break;
			case 4:
				cout << "\nGood Bye!!";
				break;
		} // end switch
	} // end while
	return 0;
} // end main
