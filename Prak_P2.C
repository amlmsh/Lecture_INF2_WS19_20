/*
 * Prak_P2.C
 *
 *  Created on: 15.05.2018
 *      Author: aml
 */

#include "Prak_P2.H"

#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <sys/time.h>



using namespace std;

namespace P2{

void P2A00(){

	complexNmbClass::complexNmb aC, bC;
	cout << "Ausgabe fuer die Implementierung als Klasse:";
	cout << "\n 1.Ausgabe a: ";
	aC.out();

	cout << "\n 2.Ausgabe a: ";
	aC.re(-2.12);
	aC.out();


	cout << "\n 3.Ausgabe a: ";
	aC.im(32.12);
	aC.re(-2.12);
	aC.out();

	cout << "\n 4.Ausgabe a (conj): ";
	aC.con();
	aC.out();


	cout << "\n 5.Ausgabe b: ";
	bC.re(2.1);
	bC.im(9.9);
	bC.out();

	cout << "\n a + b: ";
	aC.add(bC);
	aC.out();


	complexNmbStruct::complexNmb aS, bS;

	cout << "\n\nAusgabe fuer die Implementierung als Struktur:";
	cout << "\n 1.Ausgabe a: ";
	out(aS);

	cout << "\n 2.Ausgabe a: ";
	aS.re = -2.12;
	out(aS);


	cout << "\n 3.Ausgabe a: ";
	aS.im = 32.12;
	aS.re = -2.12;
	out(aS);

	cout << "\n 4.Ausgabe a (conj): ";
	aS = con(aS);
	out(aS);


	cout << "\n 5.Ausgabe b: ";
	bS.re = 2.1;
	bS.im = 9.9;
	out(bS);

	cout << "\n a + b: ";
	out(add(aS,bS));

	cout << endl;
	return;
}

void P2A01(){
	Point2D p1,p2;

	p1.setX(2,3);
	p2.setX(4,5);

	p1.out();
	p2.out();

	Rectangle R;

	R.out();
	R.set(p1,p2);
	R.out();

	RectangleArea Rarea;
	Rarea.set(R.getP1(),R.getP2());

	cout << "\n area of rectangle ";
	R.out();

	cout << " : " << Rarea.area() << endl;

	RectangleOptArea Ropt;
	Ropt.set(R.getP1(),R.getP2());

	cout << "\n area of rectangle (opt) ";
	R.out();

	cout << " : " << Ropt.area() << endl;

}


namespace complexNmbClass{

	void complexNmb::out(){
		printf("( %.2f + %.2fi)", re_, im_);
		return;
	}

	float complexNmb::re(){
		return re_;
	}

	float complexNmb::im(){
		return im_;
	}

	void complexNmb::re(float re){
		re_ = re;
	}

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

} // end complexNmbClass




namespace complexNmbStruct{

	void out(complexNmb a){
		if(a.im < 0){
			printf("( %.2f - %.2fi)", a.re, -a.im);
		}else{
			printf("( %.2f + %.2fi)", a.re,  a.im);
		}
	}

	complexNmb con(complexNmb a){
		complexNmb b;
		b = a;
		b.im = - a.im;
		return b;
	}

	complexNmb add(complexNmb a, complexNmb b){
		complexNmb c;
		c.re = a.re + b.re;
		c.im = a.im + b.im;
		return c;
	}

	complexNmb sub(complexNmb a, complexNmb b){
		complexNmb c;
		c.re = a.re - b.re;
		c.im = a.im - b.im;
		return c;
	}

} // end namespace complexNmbStruct



Point2D::Point2D(){
	X_ = 0;
	Y_ = 0;
}

void Point2D::setX(int X, int Y){
	X_ = X;
	Y_ = Y;
}

int  Point2D::getX(){
	return X_;
}

int  Point2D::getY(){
	return Y_;
}

void Point2D::out(){
	cout << "<" << X_ << "; " << Y_ << ">";
	return;
}



void Rectangle::set(Point2D P1, Point2D P2){
	P1_ = P1;
	P2_ = P2;
	return;
}

Point2D  Rectangle::getP1(){
	return P1_;
}

Point2D  Rectangle::getP2(){
	return P2_;
}

void Rectangle::out(){
	cout << "{ ";
	cout << "<" << P1_.getX() << "; " << P1_.getY() << ">";
	cout << "; ";
	cout << "<" << P2_.getX() << "; " << P2_.getY() << ">";
	cout << " }";
}



int RectangleArea::area(){
	cout << "[class RectangleArea]";
	int diffX = this->getP1().getX() - this->getP2().getX();
	int diffY = this->getP1().getY() - this->getP2().getY();
	int res   = diffX*diffY;

	if(res < 0){
		return -res;
	}else{
		return res;
	}
}

void RectangleOptArea::set(Point2D P1, Point2D P2){
	RectangleArea::set(P1,P2);
	area_ = RectangleArea::area();
	return;
}

int RectangleOptArea::area(){
	cout << "[class RectangleOptArea]";
	return area_;
}


ListOfNumbers::ListOfNumbers(){
	dataField_ = NULL;
	size_ = 0 ;
	srand(time(NULL));
}

ListOfNumbers::~ListOfNumbers(){
	if(dataField_ != NULL){
		delete [] dataField_;
		size_ = 0;
	}
}

void ListOfNumbers::init(int n){
	if(dataField_ != NULL){
		delete [] dataField_;
		size_ = 0;
	}

	if (n < 0){
		dataField_ = NULL;
		size_ = 0;
		return;
	}else {
		try{
			dataField_ = new int[n];
			size_ = n;
		}catch(...){
			dataField_ = NULL;
			size_ = 0;
			return;
		}
	}

	for(int i=0; i < size_; i++){
		dataField_[i] = i + 1;
	}
}

int  ListOfNumbers::size(){
	return size_;
}

int  ListOfNumbers::getElement(int index){
	if(index < 0) throw string("out of range");
	if(index > (size_ - 1) ) throw string("out of range");
	return dataField_[index];
}


void  ListOfNumbers::out(){
	if(dataField_ == NULL){
		cout << "[]";
		return;
	}
	cout << "[ ";
	for(int i=0; i < (size_-1); i++){
		cout << dataField_[i] << ", ";
	}
	cout << dataField_[size_-1] << "]";
	return;
}

void SwapShuffle::shuffle(){
	int z, tmp;
	for(int i; i < size_; i++){
		z = rand() % size_;
		tmp = dataField_[i];
		dataField_[i] = dataField_[z];
		dataField_[z] = tmp;
	}
	return;
}

void ProbShuffle::shuffle(){
	int z, tmp;
	bool found;
	for(int i=0; i < size_; i++){
		do{
			found = false;
			z = (rand() % size_) + 1;
			for(int j=0; j < i; j++){
				if(dataField_[j] == z){
					found = true;
					break;
				}
			}
		}while(found);
		dataField_[i] = z;
	}
	return;
}

long int ShuffleTimer::measureShuffle(IListOfNumbers *list, int n){
	static struct timeval startTime;
	static struct timeval endTime;

	gettimeofday(&startTime, NULL);
	for(int i=0; i < n; i++){
		list->shuffle();
	}
	gettimeofday(&endTime, NULL);


	long int resTime_sec  = endTime.tv_sec  - startTime.tv_sec;
	long int resTime_usec = endTime.tv_usec - startTime.tv_usec;
	if(resTime_usec < 0){
		resTime_sec--;
		resTime_usec += 1000000;
	}

	long int totalTimeMicroSec = resTime_sec*1000000;
	totalTimeMicroSec += resTime_usec;

	return totalTimeMicroSec;
}

void P2A02(){
	ProbShuffle probList;
	SwapShuffle swapList;

	IListOfNumbers *list = &swapList;


	list->init(13);
	for(int i=0; i < 10; i++){
		cout << i << ": \t";
		list->out();
		cout << endl;
		list->shuffle();
	}
	return;
}

void P2A03(){
	ProbShuffle probList;
	SwapShuffle swapList;
	ShuffleTimer timer;

	IListOfNumbers *list;
	float scale = 0.1;


	for(int i = 10; i <= 1000; i=i+10){
		probList.init(i);
		swapList.init(i);

		cout << i << "\t";
		cout << timer.measureShuffle(&swapList, 100) << "\t";
		cout << timer.measureShuffle(&probList, 100) << "\t";
		cout << scale*(i*i*log(i));
		cout << endl;
	}

	return;
}


}
