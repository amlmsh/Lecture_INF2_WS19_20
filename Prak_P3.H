/*
 * Prak_P3.H
 *
 *  Created on: 08.06.2018
 *      Author: aml
 */

#ifndef PRAK_P3_H_
#define PRAK_P3_H_

#include <string>

#include "Prak_P2.H"

using namespace std;

namespace P3{



class ICreature{
public:
	virtual string name() = 0;
	virtual string eats() = 0;
	virtual string says() = 0;
};

class Fish : public ICreature{
public:
	virtual string name();
	virtual string eats();
	virtual string says();
};

class Cat : public ICreature{
public:
	virtual string name();
	virtual string eats();
	virtual string says();
};

class Sheep : public ICreature{
public:
	virtual string name();
	virtual string eats();
	virtual string says();
};

class Avatar : public ICreature{
public:
	virtual string name();
	virtual string eats();
	virtual string says();
};


class ICreatureFactory{
public:
	virtual ICreature *produceCreatureRandomly() = 0;
};

class CreatureFactory : public ICreatureFactory{
public:
	ICreature *produceCreatureRandomly();
protected:
	ICreature *produceCreature(int n);
};


class IListOfNumbers{
public:
	virtual void     init(int n) = 0;
	virtual int      size() = 0;
	virtual int      getElement(int index) = 0;
	virtual void     out() = 0;
	virtual void     shuffle() = 0;
	virtual void     sort() = 0;
};

class ListOfNumbers : public IListOfNumbers{
public:
	ListOfNumbers();
	~ListOfNumbers();
	virtual void init(int n);
	virtual int  size();
	virtual int  getElement(int index);
	virtual void out();
protected:
	int *dataField_;
	int size_;
};



class SwapShuffle : public ListOfNumbers{
protected:
	long int opCounter_= 0;
public:
	void shuffle();
	long int getOpCounter();
};

class SortAndShuffle : public SwapShuffle{
public:
	void sort();
};

class MergeSort : public SwapShuffle{
public:
	// return number of basic computational steps
	void sort();
private:
	// return number of basic computational steps
	void mergeSort(int level, int lStartIdx, int lEndIdx);
	// return number of basic computational steps
	void merge(int l, int m, int r);
};


class SelectionSort : public SwapShuffle{
public:
	// return number of basic computational steps
	void sort();
};

class InsertionSort : public SwapShuffle{
public:
	// return number of basic computational steps
	void sort();
};


template<typename T>
class IDataItem{
	virtual T    get()           = 0;
	virtual void set(T value)    = 0;
	virtual string toXmlString() = 0;
};


template<typename T>
class DataItem : IDataItem<T>{
protected:
	T value_;
	string typeName_;
	string toString();
public:
	DataItem(string name = string("unspecified"));
	T    get();
	void set(T value);
	string toXmlString();
};


class advComplNmb : public P2::complexNmbClass::complexNmb{
	friend ostream &operator<< (ostream &ostr, const advComplNmb &rhs);
};



class IVehicle{
	virtual int    nmbOfPassanger() = 0;
	virtual int    yearOfManufacturer() = 0;
	virtual string name() = 0;
	virtual string xmlStr() = 0;
};

class ILandVehicle : public IVehicle{
	virtual int nmbWheels() = 0;
};

class IWaterVehicle : public IVehicle{
	virtual int floatingDepth() = 0;
};

class  IAmphibianVehicle : public ILandVehicle, IWaterVehicle{
	virtual int groundClearance() = 0;
};


class ISailingVessel : public IWaterVehicle{
	virtual int nmbMasts() = 0;
};

class IMotorVessel : public IWaterVehicle{
	virtual int nmbPS() = 0;
};

class IMotorSailer : public ISailingVessel, public IMotorVessel{
	virtual int minNmbCrew() = 0;
};


class Truck{

};

class Bicycle{

};

class Bus{

};


void P3A00();
void P3A01();
void P3A02();
void P3A03();
void P3A04();


} // end namespace P3

#endif /* PRAK_P3_H_ */
