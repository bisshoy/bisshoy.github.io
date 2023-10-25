////////////////////////////////////////
// FILES NEEDED:					  //
//									  //
// main.cpp							  //
// dictionary.h						  //
// dictionary.cpp					  // 
// fraction.h 						  //
// fraction.cpp						  // 
// stack.h							  // 
//								  	  //
////////////////////////////////////////

#include <iostream>
#include "fraction.h"
#include "dictionary.h"
#include "stack.h"

// You'll need your fraction class from project 1, 
// the stack template class from that one lab, and 
// you'll need to make your own dictionary class 

// NOTE: YOU WILL NEED TO MAKE YOUR OWN DICTIONARY
// Fortunately, Kramer has a version from a year ago 
// on his GitHub (that's what I used, with some 
// modifications). Here are the links: 
// 
// Header file: https://github.com/SnowyOwl000/3700.f22.public/blob/main/Project%20Files/2%20-%20Calculator/dictionary.h
// Implem file: https://github.com/SnowyOwl000/3700.f22.public/blob/main/Project%20Files/2%20-%20Calculator/dictionary.cpp
// 
// Don't bother making the remove function, since you 
// never need to remove any dictionary entries. 

using namespace std;

// This is the struct for the operands, which go in the 
// numStack 
struct operand {
	string name;
	Fraction value;
}

// These are the two stacks you'll need 
Stack<operand> numStack;
Stack<char> opStack;

// HOW THE PROGRAM RUNS 

void doOp() {
	// This actually does the evaluating 
	// IT DOES NOT TAKE ANY PARAMETERS
	// You pop the numStack twice and the opStack once 
	// The first thing popped from the numStack is the right-hand side 
	// The second thing popped from the numStack is the left-hand side 
	// And then you pop the opStack once to get the operator 
	// Basically: 

	// (Left side is the bottom, right side is the top)
	// NUMSTACK: 5 4
	// OPSTACK : +

	// rhs = numStack.pop() = 4
	// lhs = numStack.pop() = 5
	// op  =  opStack.pop() = +
	// So it should do:
	// 5 + 4
	// and return 9 

	operand rhs = numStack.pop();
	operand lhs = numStack.pop();
	char op = opStack.pop();

	// You could do, like, a massive if/else-f/else statement here,
	// like:

	if (/*op == '+'*/) {

		// do addition of lhs and rhs 

	}

	else if (/*op == '-'*/) {

		// do subtraction of lhs and rhs 

	}

	else if (/*op == '*'*/) {

		// do multiplication of lhs and rhs 

	}

	else if (/*op == '/'*/) {

		// do division of lhs and rhs 

	}

	else if (/*op == '='*/) {

		// Handle assignment 
	
	}

	else {
		cout << "That wasn't an operator you fuckass." << endl;
	}

	// or some shit 

}

bool hasPrecedence(char c1, char c2) {
	// This compares the top operator in the 
	// opStack against the next thing in the user's 
	// input string 

	// Return TRUE if opStack character has precedence 
	// Uhh, I might have that backwards. IDK. 

	// This function is used INSIDE EVALUATE 

	// Basically, this is PEMDAS 
}

void evaluate(string s) {
	// THIS IS ALGORITHM 1 ON PAGE 3 OF THE ASSIGNMENT 
	// SHEET!!!!!!!!!!

	// Clear numStack
	numStack.clear();
	
	// Clear opStack
	opStack.clear();

	// Push $ onto opStack
	opStack.push('$');

	// first <- 0
	int first = 0;

	while (/* first < s.length() */) {
		operand tmp; 

		// IF IT'S A NUMBER 
		if (/* isdigit(s[first]) */) {

			// Convert digit sequence into fraction 
				// You can do this by making an empty string,
				// adding each consecutive isdigit character 
				// to it, then taking the whole thing and using
				// the stoi function 
				// 
				// There are other ways to do this, however 
			
			// Store Fraction object in structure and push onto numStack 
				// Each thing in the numStack is an operand (from the struct
				// on line 25). If it's a number, you do
				// 
				// tmp.value = num
				// tmp.name  = ""
			
			// Advance first to first character past the digit sequence 
		
		}

		// IF IT'S A VARIABLE 
		else if (/* isalpha(s[first]) */) {
			
			// Extract name into string 
				// This is an easier version of the above 

			// Store Fraction object in structure and push to numStack 
				// Basically, same as above except since it's a variable,
				// it'll be like:
				//
				// tmp.name = varName;

			// Advance first to first character past the variable name  
		
		}

		// IF IT'S A (
		else if (/* s[first] == '(' */) {

			// Push ( onto opStack
			opStack.push('(');

			// Increment first 
			first++;

		}

		// IF IT'S A )
		else if (/* s[first] == ')' */) {
			
			while (/* top of opStack is not ( */) {

				// perform top operation 
				doOp();

			}
		
			// Pop ( from top of opStack
			opStack.pop();

			// Increment first
			first++;

		}

		// IF IT'S AN OPERATOR 
		else if (/* s[first] is a +, -, *, /, or = */) {
			
			// While top of opStack hasPrecedence over s[first]
			while (hasPrecedence()) { 

				// perform top operation 
				doOp();

			}

			// Push s[first] onto opStack
			opStack.push(s[first]);

			// Increment first 
			first++;

		}

	}

	// While top of opStack is not $ 
	while (/* opStack.peek() != '$' */) {

		// perform top operation 
		doOp();

	}

	cout << numStack.pop() << endl;

}

void debugger(string s) {

	// This is going to pretty much be the same as 
	// evaluate, but everything goes into one stack 
	// and you pop them all out in reverse order. 

	// You can just look up how to reverse a stack, 
	// it's a very common problem online and pretty 
	// easy 

}

int main(int argc, char* argv[]) {
	// The argc and argv above are so that your program 
	// can read any "flags" input. For example:
	// 
	// ./project2 -t
	// 
	// The "-t" is the flag. This can be done in an if
	// statement at the beginning, so basically:
	// 
	// 1) Run the program 
	// 2) Check if "-t" has been added 
	// 3) If it has, then you run debug 
	// 4) If it has not, then you just run 
	//    the normal evaluate 

	if (/* the user input "-t"*/) {

		// Run debug until the user inputs "#"

		return 0;
	}

	// If they did not input "-t"
	// PUT A WHILE-LOOP HERE that keeps evaluating 
	// until the user inputs a "#"

	return 0;
}