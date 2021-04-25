/*
 * V03.C
 *
 *  Created on: 08.05.2018
 *      Author: aml
 */

#include "V03.H"

using namespace V03;

void demoV03_komplexeZahlen(){
	complexNmb a, b;

	// 1. Ausgabe
	printf("\n\n 1.Ausgabe a: ");
	a.out();

	// 2. Veraendere Daten und Ausgabe
	a.re(-2.12);
	printf("\n 2.Ausgabe a: ");
	a.out();

	// 3. Veraendere Daten und Ausgabe
	a.im(32.12);
	a.re(-2.12);
	printf("\n 3. Ausgabe a: ");
	a.out();

	// 4. Berechne konjungation
	printf("\n 4. Ausgabe: a conj =  ");
	a.con();
	a.out();

	b.re(2.1);
	b.im(9.9);

	// 5. Ausgabe
	printf("\n 5.Ausgabe b: ");
	b.out();

	// 6. Ausgabe
	printf("\n a + b: ");
	a.add(b);
	a.out();
}


namespace V03{

/**
 *
 *
 */
void complexNmb::out(){
	printf("( %.2f + %.2fi)", re_, im_);
	return;
}

/**
 *
 *
 */
float complexNmb::re(){
	return re_;
}

/**
 *
 *
 */
float complexNmb::im(){
	return im_;
}

/**
 *
 *
 */
void complexNmb::re(float re){
	re_ = re;
}

/**
 *
 *
 */
void complexNmb::im(float im){
	im_ = im;
}

void complexNmb::con(){
	im_ = - im_;
	return;
}

void complexNmb::add(complexNmb b){
	re_ = re_ + b.re_;
	im_ = im_ + b.im_;
	return;
}

void complexNmb::sub(complexNmb b){
	re_ = re_ - b.re_;
	im_ = im_ - b.im_;
	return;
}

void complexNmb::mul(complexNmb b){
	re_ = (re_ * b.re_) - (im_ * b.im_);
	im_ = (re_ * b.im_) + (im_ * b.re_);
	return;
}

void complexNmb::div(complexNmb b){
	float norm = (b.re_ * b.re_) + (b.im_ * b.im_);
	re_ = ( (re_ * re_) - (im_ * b.im_) ) / norm;
	im_ = ( (im_ * re_) + (re_ * b.im_) ) / norm;
	return;
}

} // end namespace V03

