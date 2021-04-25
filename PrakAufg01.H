/*
 * PrakAufg03.H
 *
 *  Created on: 17.04.2018
 *      Author: aml
 *
 *
 *      SW-Framework fuer Praktikumsaufgabe 1
 *
 *
 */

#ifndef PRAKAUFG01_H_
#define PRAKAUFG01_H_

/**
 *
 * \file PrakAufg01.H
 *
 * \brief Contains all the class definitions
 * for the stack implementation.
 *
 * This file is the base for solving the
 * semester programming task 1 (PrakAufg01).
 *
 * It starts with the interface class
 * that shall serve as base for all the
 * implementations.
 * Thus, all classes should be derived from
 *
 *
 *
 */

#include <string>
using namespace std;


namespace SemesterProgramming{

/**
 *
 * \brief Interface class for all Stack classes.
 * The stack can store items of type char.
 *
 *
 */
class ICharStack{
public:
	/**
	 *
	 * \brief This method initializes the
	 * stack. When calling this method the existing
	 * stack will be deleted, meaning all item in the
	 * stack still stored are lost.
	 * The memory of the stack is deleted as well
	 * and new memory of the given size will be allocated
	 * again.
	 *
	 */
	virtual void init(int size = 100) = 0;

	/**
	 *
	 * \brief All items in the stack will be
	 * removed. After calling this method the
	 * stack is empty.
	 *
	 */
	virtual void clear() = 0;

	/**
	 *
	 *  \brief Returns the state of the stack.
	 *  Return value is true if the stack is initialised
	 *  and can not store any items anymore, otherwise it return false.
	 *
	 *  \return bool
	 *
	 */
	virtual bool isEmpty() = 0;

	/**
	 *
	 * \brief Return the state of the stack.
	 *
	 * Return value is true if the stack can
	 * not store any items or if the stack is
	 * not initialised; otherwise false.
	 *
	 *
	 */
	virtual bool isFull() = 0;


	/**
	 *
	 * \brief Returns the size of the stack
	 * If the stack is not initialized it returns 0
	 *
	 * \return int size of the stack
	 *
	 */
	virtual int size() = 0;

	/**
	 *
	 * \brief Removes the top item
	 * of the stack and returns it.
	 *
	 * \return char element on top
	 *
	 * \throws string if stack contains no items
	 * or if not initialized.
	 *
	 */
	virtual char pop() = 0;

	/**
	 *
	 * \brief Inserts the item into the stack.
	 *
	 *
	 * \@param char c item to be inserted to the stack.
	 *
	 * \return true if the item  is stored, otherwise false.
	 *
	 */
	virtual bool push(char c) = 0;

	/**
	 *
	 * \brief Delivers the top item of the stack
	 * without removing it from the stack.
	 *
	 * \return char element on top
	 *
	 * \throws string if stack contains no items
	 * or if not initialized.
	 *
	 */
	virtual char peek() = 0;

};

/**
 *
 * \brief class for testing instance of ICharStack
 *
 */
class TestCharStack{
public:

	/**
	 *
	 * \brief Constructor
	 *
	 */
	TestCharStack(ICharStack *stack);

	/**
	 * \brief Runs all tests.
	 *
	 * \return true if all test successfully passed, otherwise false
	 *
	 */
	bool runTest();

protected:

	/**
	 *
	 * Unit tests
	 */
	bool testConstructor(string testName);

	/**
	 *
	 * Unit tests
	 *
	 */
	bool testInitSize(string);

	/**
	 *
	 * Unit tests
	 *
	 */
	bool testInitClear(string);

	/**
	 *
	 * Unit tests
	 *
	 */
	bool testIsEmpty(string);

	/**
	 *
	 * Unit tests
	 *
	 */
	bool testIsFull(string);

	/**
	 *
	 * Unit tests
	 *
	 */
	bool testPopPush(string);

	/**
	 *
	 * Unit tests
	 *
	 */
	bool testPeek(string);

	/**
	 *
	 * Reference to the stack to be tested.
	 */
	ICharStack *testStack_;
};


/**
 *
 * Class implementing ICharStack
 *
 */
class CharStack : public ICharStack{
public:

	/**
	 *
	 * Constructor
	 */
	CharStack(int size = 100);
	~CharStack();

	void init(int size);
	void clear();
	bool isEmpty();
	bool isFull();
	int  size();
	char pop();
	bool push(char c);
	char peek();

protected:

	/**
	 *
	 * Counter of the elements stored in the stack
	 *
	 */
	int size_;

	/**
	 *
	 *  Reference to  the memory storing the
	 *  elements of the stack
	 *
	 */
	char *dataField_;

	/**
	 *
	 * Contains the index of the last element
	 * of the stack stored
	 *
	 */
	int idxLastElement_;
};


/**
 *
 *  Stack that contains only "digit chars" which represent
 *  a non-negative integer number.
 *
 *	If initialized with no string, an empty string or a string
 *	containing only non-digit then the
 *	stack contains only digit '0'.
 *
 *  The digits are stored according to the order.
 *	The digit of the lowest order is on the top of the stack.
 *
 */
class NumberStack : private CharStack{
public:

	/**
	 *
	 * construstor
	 */
	NumberStack(string s="");

	/**
	 *
	 * Constructor
	 */
	NumberStack(NumberStack *nmbStack);

	/**
	 *
	 * Destructor
	 */
	~NumberStack();

	/**
	 *
	 * Adds the given digit stack to current stack
	 * and returns the result in a new stack
	 *
	 */
	NumberStack *add(NumberStack *number);

	/**
	 *
	 * Returns a string representing the
	 * number stored in the current stack.
	 *
	 */
	string toStr();

	/**
	 *
	 * Returns the number of digits stored in the stack.
	 *
	 */
	int sizeNumber();


	/**
	 *
	 *
	 */
	int size();
};


}  // end namespace SemesterProgramming


#endif /* PRAKAUFG01_H_ */
