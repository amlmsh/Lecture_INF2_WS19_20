/*
 * prakAufg01Main.C
 *
 *  Created on: 27.04.2018
 *      Author: aml
 */


#include "PrakAufg01.H"

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace SemesterProgramming;

int main(){



	ICharStack *stack;
	stack = new CharStack();

	// Test Stack type
	TestCharStack test(stack);

	test.runTest();

	// User input
	string strOp1, strOp2;
	cout << "Erste  Zahleneingabe (>0) Op1:";
	cin >> strOp1;
	cout << "Zweite Zahleneingabe (>0) Op2:";
	cin >> strOp2;

	NumberStack *op1 = new NumberStack(strOp1);
	NumberStack *op2 = new NumberStack(strOp2);
	NumberStack *res = new NumberStack();
	res = op1->add(op2);



	cout << "  " << setw(res->size()) << op1->toStr() << endl;
	cout << "+ " << setw(res->size()) << op2->toStr() << endl;
	cout << "= " << setw(res->size()) << res->toStr() << endl;

	cout << "\n";
}

