/*
AIM:
Implement C++ program for expression conversion 
as infix to postfix 
and its evaluation using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/' operators are expected

INPUT: 
    1. Infix Expression
	
OUTPUT:
	1) Display postfix expression
	

AUTHOR:  Sunil
DATE: 15.10.2024
*/
#include<iostream>
#include<string.h>
#define MAX 10
using namespace std;

//ADT Stack
class Stack{
	private:
		char S[MAX];//Stack array
		int top;//pointer to the top element of a stack
	public:
		Stack(){
			top=-1;//Stack empty means top points to invalid location
		}
		
		//check if stack is empty
		bool isStackEmpty(){
			if (top == -1)
				return true;
			else
				return false;
		}
		
		//check if stack is full
		bool isStackFull(){
			if (top == MAX-1)
				return true;
			else
				return false;
		}
		
		//Add element in stack 'Push Operation'
		void push(char token){
				if(! isStackFull())
					S[++top]=token;
				else
					cout<<"\nStack is full!!";
		}
		
		//Remove element from stack 'Pop Operation'
		char pop(){
				if(!isStackEmpty()){
					cout<<"\n"<<S[top]<<"  is popped from Stack";
					return S[top--];
				}
				else
					cout<<"\nStack is Empty!!";
				
				return '\0';
		}
		
		//Top()
		char Top(){
			return S[top];
		}
		
		//Display stack contents
		void displayStack(){
			int i;
			if(!isStackEmpty()){
				for (i=top;i>=0; i--)
					cout<<"\n"<<S[i];
			}
			else
				cout<<"\n Stack Empty!!";
		}
};


//Implementation class
class ExpressionConversion{
	private:
		char E[20];//an array to store an infix expression
		Stack stk;
	public:
		ExpressionConversion(){
		}
		
		void readExpression(){
			strcpy(E,"");
			cin>>E;
		}
		
		void displayExpression(){
			cout<<"\nThe input infix expression is:"<<E;
		}
		
		int ICP(char t)
		{
			int v;
			switch(t)
			{
				case '+':
				case '-':
					v=1;
					break;
				case '*':
				case '/':
					v=2;
					break;
				case '^':
					v=3;
					break;
				case '(':
					v=4;
					break;
			}
			return v;
		}
		
		int ISP(char t)
		{
			int v;
			switch(t)
			{
				case '+':
				case '-':
					v=1;
					break;
				case '*':
				case '/':
					v=2;
					break;
				case '^':
					v=3;
					break;
				case '(':
					v=0;
					break;
			}
			return v;
		}
	
		void in2Post()
		{
			
			char POST[20];
			int i,j=0;
			i=0;
			while(E[i] != '\0')
			{
				if(E[i]=='+' || E[i]=='-' ||E[i]=='*' ||E[i]=='/' |E[i]=='^' ||E[i]=='(')
				{
					if(stk.isStackEmpty())
					{
						stk.push(E[i]);
					}
					else
					{
						while(ICP(E[i]) <= ISP(stk.Top()) && !stk.isStackEmpty())
							POST[j++]=stk.pop();
			  
						stk.push(E[i]);
					}
				}
				else
					if(E[i] == ')')
					{
						while(stk.Top() != '(')
							POST[j++]=stk.pop();
						stk.pop();
					}
					else
						POST[j++]=E[i];

					i++;
			}
  
			while(!stk.isStackEmpty())
				POST[j++]=stk.pop();//here I wrote E
  
			POST[j]='\0';
			cout<<"\nThe prefix expression is ::"<<POST;
		}

};//end class

//Driver Code
int main(){
	int choice=0;

	ExpressionConversion obj ;
	while(choice != 4){
		cout<<"\n***************INFIX to POSTFIX*****************";
		cout<<"\n1. Read Infix Expression";
		cout<<"\n2. Display Infix Expression";
		cout<<"\n3. Convert Expression";
		cout<<"\n4. Exit Application";
		cout<<"\nWhat is your choice::";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter Infix Parenthesized Expression:";
				obj.readExpression();
				break;
			case 2:
				obj.displayExpression();
				break;
			case 3:
				obj.in2Post();
				break;
			case 4:
				cout<<"\nGood By!!";
				break;
			
		}//end switch
	}//end while
	return 0;
}//end main


/*


int main(){
	Stack stk;
	int a,b,c;
	char ch='1';
	stk.push('A');
	stk.push('B');
	stk.push('C');
	stk.push('D');
	cout<<"\nStack is:";
	stk.displayStack();
	cout<<endl;
	stk.pop();
	stk.pop();
	
	cout<<"\nStack is:";
	stk.displayStack();
	cout<<endl;
	
	stk.pop();
	stk.pop();
	
	cout<<"\nStack is:";
	stk.displayStack();
	c=((a));
	a=1;
	cout<<"\n***********\n";
	cout<<a<<endl;
	cout<<int(ch)<<endl;
	cout<<char(ch)<<endl;
	return 0;
}

*/