/*
* converter.cpp
* provides implementation of functions declared in convert.h
*/

#include <iostream>
#include "converter.h"
#include "stack.h"
#include "LinkedList.h"

using namespace std;

bool isOperand(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '(' || op == ')')
		return false;
	return true;
}

int precedence(char op)
{
	if (op == '*' || op == '/')
		return HIGHPRECEDENCE;
	if (op == '+' || op == '-')
		return LOWPRECEDENCE;
	return -1;
}

string infix_to_postfix(string Ei)
{
	//have to go around top stack
	//maybe use Eo to copy the current top stack and overwrite it each time a new top is made
	stack S;
	char op;  
	char meaningfullname;
	string Eo = "";  
	for (int i = 0; i < Ei.length(); i++)
		if (isOperand(Ei[i]))
		Eo += Ei[i];    
		else      
			if (Ei[i] == '(')   
				S.push(Ei[i]);
		else
			if (Ei[i] == ')')    
				while ((op = S.pop()) != '(')  
					Eo += op;
			else // Ei[i] is an operator.
			{
				while (!S.isEmpty()) {
					meaningfullname = S.pop();
					S.push(meaningfullname);
					if (precedence(Ei[i]) > precedence(meaningfullname)) {
						break;
					}
					else {
						Eo += S.pop();
					}
				}
				S.push(Ei[i]);
			}

	while (!S.isEmpty())  
		Eo += S.pop();
	return Eo;
}

bool valid_parentheses(string E)
{
	stack S;
	for (int i = 0; i < E.length(); i++)
	{
		if (E[i] == '(')
			S.push(E[i]);
		if (E[i] == ')')
			S.pop();
	}
	return S.isEmpty();
}
