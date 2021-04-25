/*
 * V06.H
 *
 *  Created on: 20.06.2018
 *      Author: aml
 */

#ifndef V06_H_
#define V06_H_

#include <iostream>

using namespace std;

namespace V06{

class A{
public:
	void out(){cout << "A" << endl;};
};

class B : public A{
public:
	void out(){cout << "B" << endl;};
};

class C : public A{
public:
	void out(){cout << "C" << endl;};
};

class vA{
public:
	virtual void out(){cout << "vA" << endl;};
};

class vB : public vA{
public:
	virtual void out(){cout << "vB" << endl;};
};

class vC : public vA{
public:
	virtual void out(){cout << "vC" << endl;};
};


class Employee{
public:
	int ID_;
	string name_;
	string department_;
	int pay_;
};

class Manager : public Employee{
public:
	Employee deputy_;
	Employee *employes_;
};

class Director : public Manager{
public:
	Manager *managers_;
};


class Prints{
public:
	string ISBN_;
	int yearOfPublishing_;
};

class Proceedings : public Prints{
public:
	string *editors_;
	string conference_;
};

class Paper : public Proceedings{
public:
	string *authors_;
	string title_;
};


class Journal : public Prints{
public:
	string title_;
	string *editors_;
	int vol_;
	int nmb_;
};

class Article : public Journal{
public:
	string *authors_;
	string title_;
};

class Book : public Prints{
public:
	string *authors_;
	string title_;
	int nmbPages_;
};



class Numbers {
public:
	~Numbers();
	void init(int n);
	void set(int idx, int value);
	int  get(int idx);
	void sort();
	void print();
protected:
	int *dataField_ = NULL;
	int  size_ = 0;
};

class SelectionSort : public Numbers{
public:
	void sort();
};

class MergeSort : public Numbers{
public:
	void sort();
private:
	// return number of basic computational steps
	void mergeSort(int lStartIdx, int lEndIdx);
	// return number of basic computational steps
	void merge(int l, int m, int r);
};

}


void demoV06_00();
void demoV06_01();

#endif /* V06_H_ */
