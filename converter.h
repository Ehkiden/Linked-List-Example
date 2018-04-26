/*
* File:   converter.h
* Author: Pike
*
*/

#ifndef CONVERTER_H
#define	CONVERTER_H

#include <string>

using namespace std;

const int HIGHPRECEDENCE = 2;
const int LOWPRECEDENCE = 1;

// Check if the op is an operand
// returns true if yes, otherwise false
bool isOperand(char op);

// return the corresponding constant integer value of the op
// if op is either "*" or "/", it returns HIGHPRECEDENCE;
// if op if either "+" or "-", it returns LOWPRECEDENCE.
int precedence(char op);

// convert the infix_exp, which is an infix expression, 
// into its corresponding postfix expression
string infix_to_postfix(string infix_exp);

// check if infix_exp contains matched parentheses
// returns true if yes, otherwise false
bool valid_parentheses(string infix_exp);

#endif	/* CONVERTER_H */
