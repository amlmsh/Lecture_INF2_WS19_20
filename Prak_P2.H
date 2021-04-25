/*
 * Prak_P2.H
 *
 *  Created on: 15.05.2018
 *      Author: aml
 */

#ifndef PRAK_P2_H_
#define PRAK_P2_H_

#include <string>

namespace P2{

namespace complexNmbStruct{

	// Datentyp
	typedef struct {
		float re = 0.0;
		float im = 0.0;
	}complexNmb;

	// Operatoren
	void       out(complexNmb a);
	complexNmb con(complexNmb a);
	complexNmb add(complexNmb a, complexNmb b);
	complexNmb sub(complexNmb a, complexNmb b);

}


namespace complexNmbClass{

	class complexNmb{
	protected:
		float re_ = 0;
		float im_ = 0;
	public:
		float re();
		float im();
		void  re(float re);
		void  im(float im);
		void  out();
		void  con();
		void  add(complexNmb b);
		void  sub(complexNmb b);
	};

}


class Point2D{
	int X_;
	int Y_;
public:
	Point2D();
	void setX(int X, int Y);
	int  getX();
	int  getY();
	void out();
};


class Rectangle{
	Point2D P1_;
	Point2D P2_;
public:
	void set(Point2D P1, Point2D P2);
	Point2D  getP1();
	Point2D  getP2();
	void out();
};

class RectangleArea : public Rectangle{
public:
	int area();
};

class RectangleOptArea : public RectangleArea{
	int area_;
public:
	int  area();
	void set(Point2D P1, Point2D P2);
};

class IListOfNumbers{
public:
	/**
	 *
	 * Initiates the list of n numbers having
	 * values between 1 und n. After this
	 * method call the list is sorted, starting
	 * at index x with value 1
	 */
	virtual void init(int n) = 0;

	/**
	 *
	 * Returns the size of the list
	 *
	 */
	virtual int  size() = 0;

	/**
	 *
	 * Returns the value of the element
	 * at the given index.
	 *
	 */
	virtual int  getElement(int index) = 0;

	/**
	 *
	 * Generates an output of the list stored
	 * on the standard output (screen).
	 */
	virtual void out() = 0;

	/**
	 *
	 * Shuffles the list. After this method call
	 * the list is not sorted anymore.
	 */
	virtual void shuffle() = 0;
};

class ListOfNumbers : public IListOfNumbers{
public:
	ListOfNumbers();
	~ListOfNumbers();
	virtual void init(int n);
	virtual int  size();
	virtual int  getElement(int index);
	virtual void out();
	virtual void shuffle() = 0;
protected:
	int *dataField_;
	int size_;
};


class ProbShuffle : public ListOfNumbers{
public:
	void shuffle();
};

class SwapShuffle : public ListOfNumbers{
public:
	void shuffle();
};

class ShuffleTimer{
public:
	long int measureShuffle(IListOfNumbers *list, int n);
};



void P2A00();
void P2A01();
void P2A02();
void P2A03();

}

#endif /* PRAK_P2_H_ */
