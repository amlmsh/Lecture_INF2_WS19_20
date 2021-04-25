/*
 * V02.C
 *
 *  Created on: 01.05.2018
 *      Author: aml
 */

#include <iostream>

using namespace std;

namespace xml{

	void output(int i){
		cout << "<value>";
		cout << i;
		cout << "</value>";
		cout << endl;
	}

}

namespace str{

	void output(int i){
		cout <<  i  << endl;
	}
}


void myFunction(int i = 9){
	cout << "myFunction output: " << i << endl;
}


void swap(int   *a, int   *b){
	cout << "\tint swap\n";
	int tmp;
	tmp = *a;
	*a  = *b;
	*b  = tmp;
	return;
}

void swap(float *a, float *b){
	cout << "\tfloat swap\n";
	float tmp;
	tmp = *a;
	*a  = *b;
	*b  = tmp;
	return;
}

void swap(double *a, double *b){
	cout << "\tdouble swap\n";
	double tmp;
	tmp = *a;
	*a  = *b;
	*b  = tmp;
	return;
}

void demoV02_Overload(){
	double dblA, dblB;
	float  fltA, fltB;
	int    intA, intB;

	cout << "Overloading\n";

	swap(&fltA,&fltB);
	swap(&dblA,&dblB);
	swap(&intA,&intB);

	//swap(&fltA,&dblB);
}

void demoV02_DynMem(){
	int n = 100;

	double A;
	double *ptrA;

	ptrA = &A;  // zeigt auf Speicher des Aufrufstapels

	ptrA = new double; // zeigt auf Speicher jeneits des Aufrufstapels

	// Beschaffung des Speichers
	double staArray[n];  // im Aufrufstapel
	double *dynArray = new double[n]; // jenseits des Stapels

	// wieder freigeben den Speichers
	delete [] dynArray;
	delete ptrA;

	return;
}

void demoV02_Namespace(){
	str::output(2);
	xml::output(2);
}

void demoV02_string(){
	string a("A simple sentence with");
	string b, c;

	b = "x";
	c = a + " " + b + '.';

	cout << "output 1: " << c << endl << "output 2: ";


	for(int i=0; i < c.length(); i++){
		cout << c[i];
	}

	cout << endl << "demo finished.\n";

	return;
}

void demoV02_Exception(){
	int number;
	string tmpStr;


	/*
	while(1){
		cout << "Enter number: ";
		cin >> tmpStr;

		try{
			number = stoi(tmpStr);
			break;
		}catch(...){
			cout << "Error, repeat input: \"";
			cout << tmpStr << "\" is not a number!" << endl;
		}
	}
	*/


	while(1){
		cout << "Enter number: ";
		cin >> tmpStr;

		try{
			number = stoi(tmpStr);
			break;
		}catch(out_of_range){
			cout << "Error, repeat input: \"";
			cout << tmpStr << "\" is out of range!" << endl;
		}catch(invalid_argument){
			cout << "Error, repeat input: \"";
			cout << tmpStr << "\" is not a number!" << endl;
		}catch(...){
			cout << "Error, repeat input: \"";
			cout << tmpStr << "\" is not a number!" << "\n";
		}
	}

	cout << "Eingabe war: "  << number << endl;


}


void demoV02_StandardParam(){
	myFunction(13);
	myFunction();
}

/*
int& f(){
	int i = 19;
	return i;
}
*/

void demoV02_refrence(){
	int i = 13;
	int& ri = i;

	//int& rf = f();

	cout << "i  value:" << i  << endl;
	cout << "ri value:" << ri << endl;
	//cout << "rf value:" << rf << endl;
}
