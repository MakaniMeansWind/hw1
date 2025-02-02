/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

#include <cstddef>

// #include <iostream>

using namespace std;

/* Add a prototype for a helper function here if you need */

Node* splitHelperOdd(Node*& in, Node*& odds);

Node* splitHelperEven(Node*& in, Node*& evens);


void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

	if(in == NULL)
	{

		// cout << "In is NULL! Recursive function should end." << endl;

		return;

	}

	if(in->value % 2 == 1)
	{

		in = splitHelperOdd(in, odds);
		
		split(in, odds, evens);

	}

	else if(in->value % 2 == 0)
	{

		in = splitHelperEven(in, evens);

		split(in, odds, evens);

	}

}

Node* splitHelperOdd(Node*& in, Node*& odds)
{

	if(odds == NULL)
	{

		// cout << "Creating head node for ODDS List!" << endl;

		Node* nextInToBeProcessed = in->next;

		odds = in;

		odds->next = NULL;

		return nextInToBeProcessed;

	}

	else if(odds->next != NULL)
	{

		Node* nextInToBeProcessed = splitHelperOdd(in, odds->next);

		return nextInToBeProcessed;

	}
	
	else if(odds->next == NULL)
	{

		// cout << "Adding Node to End of Odds List!" << endl;

		Node* nextInToBeProcessed = in->next;

		odds->next = in;

		odds->next->next = NULL;

		return nextInToBeProcessed;

	}

}

Node* splitHelperEven(Node*& in, Node*& evens)
{

	if(evens == NULL)
	{

		// cout << "Creating head node for EVENS List!" << endl;

		Node* nextInToBeProcessed = in->next;

		evens = in;

		evens->next = NULL;

		return nextInToBeProcessed;

	}

	else if(evens->next != NULL)
	{

		Node* nextInToBeProcessed = splitHelperEven(in, evens->next);

		return nextInToBeProcessed;

	}
	
	else if(evens->next == NULL)
	{

		// cout << "Adding Node to End of EVENS List!" << endl;

		Node* nextInToBeProcessed = in->next;

		evens->next = in;

		evens->next->next = NULL;

		return nextInToBeProcessed;

	}

}






/* If you needed a helper function, write it here */
