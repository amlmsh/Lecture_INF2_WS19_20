/*
 * V05.C
 *
 *  Created on: 13.06.2018
 *      Author: aml
 */

#include <iostream>
#include "V05.H"

using namespace std;


namespace V05{

float complexNmb::re(){ return re_;};
float complexNmb::im(){ return im_;};
void  complexNmb::set(float re, float im){re_ = re; im_ = im;};

complexNmb complexNmb::operator-(complexNmb rhs){
	complexNmb c;
	c.re_ = re_ + rhs.re_;
	c.im_ = im_ + rhs.im_;
	return c;
}


// friend Funktion
complexNmb operator+ (complexNmb lhs, complexNmb rhs){
	complexNmb c;
	c.re_ = lhs.re_ + rhs.re_;
	c.im_ = lhs.im_ + rhs.im_;
	return c;
}


int operator> (complexNmb lhs, complexNmb rhs){
	float absLhs = lhs.re_*lhs.re_ + lhs.im_*lhs.im_;
	float absRhs = rhs.re_*rhs.re_ + rhs.im_*rhs.im_;
	if(absLhs > absRhs){
		return 1;
	}else{
		return 0;
	}
}


std::ostream & operator<<(std::ostream &lhs, V05::complexNmb rhs){
	lhs << "(" << rhs.re_<<  "+" << rhs.im_ << "i)";
	return lhs;
}














} // end namespace V05



void demoV05_overloading(){
	using namespace V05;
	complexNmb a,b,c;

	a.set(1.2, 0.4);
	b.set(3.2, 1.9);

	c = a + b;

	cout << a << " + " << b << " = " << c << endl;

};

void demoV05_templateList(){
	using namespace V05;
	complexNmb a,b,c;

	a.set(1.1,-2.2);
	b.set(-23.23,0.9);

	Set<complexNmb> l(5);
	Set<complexNmb> lcpy = l;

	l.insert(a);
	l.insert(b);
	l.insert(c);

	cout << "orig.:";
	l.out();
	cout << endl;
	cout << "copy:";
	lcpy.out();
	cout << endl;
	cout << endl;

	l.swap();

	cout << "orig.:";
	l.out();
	cout << endl;
	cout << "copy:";
	lcpy.out();
	cout << endl;
	cout << endl;

	lcpy = l;

	cout << "orig.:";
	l.out();
	cout << endl;
	cout << "copy:";
	lcpy.out();
	cout << endl;
	cout << endl;

	l.sort();


	cout << "orig.:";
	l.out();
	cout << endl;
	cout << "copy:";
	lcpy.out();
	cout << endl;
	cout << endl;



};

void demoV05_AssignmentEtc(){
	V05::complexNmb a,b;

	a.set(1.2, 2.3);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl << endl;

	b = a;  // Zuweiungsoperator

	cout << "a: " << a << endl;
	cout << "b: " << b << endl << endl;

	V05::complexNmb c = a;  // kopie-Konstrutor

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl << endl;
}

