/*
 * Prak_P3.C
 *
 *  Created on: 08.06.2018
 *      Author: aml
 */

#include "Prak_P3.H"
#include "Prak_P2.H"

#include <iostream>
#include <sstream>
#include <cmath>
#include <sys/time.h>

using namespace std;

namespace P3{

string Fish::name()   {return string("Fish");};
string Fish::eats()   {return string("little fish");};
string Fish::says()   {return string("blub blub blub");};
string Cat::name()    {return string("Cat");};
string Cat::eats()    {return string("fish");};
string Cat::says()    {return string("meow");};
string Sheep::name()  {return string("Sheep");};
string Sheep::eats()  {return string("gras");};
string Sheep::says()  {return string("meeeh");};
string Avatar::name() {return string("Avatar");};
string Avatar::eats() {return string("bitcoin");};
string Avatar::says() {return string("Hello");};


ICreature *CreatureFactory::produceCreatureRandomly(){
	return produceCreature(rand() % 4);
}

ICreature *CreatureFactory::produceCreature(int n){
	ICreature *ptrCreature;
	switch(n){
		case 0:  ptrCreature = new Fish();  break;
		case 1:  ptrCreature = new Cat();   break;
		case 2:  ptrCreature = new Sheep(); break;
		default: ptrCreature = new Avatar();break;
	}
	return ptrCreature;
};

ListOfNumbers::ListOfNumbers(){
	dataField_ = NULL;
	size_ = 0 ;
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
	for(int i=0; i < size_; i++){
		z = rand() % size_;
		tmp = dataField_[i];
		dataField_[i] = dataField_[z];
		dataField_[z] = tmp;
	}
	return;
}

long int SwapShuffle::getOpCounter(){
	return opCounter_;
}


void SortAndShuffle::sort(){
	opCounter_ = 0;
	int tmp;
	bool swaped;
	do{
		swaped = false;
		for(int i = 1; i < size_; i++){
			opCounter_ += 2;
			if(dataField_[i-1] > dataField_[i]){
				tmp = dataField_[i];
				dataField_[i] = dataField_[i-1];
				dataField_[i-1] = tmp;
				swaped = true;
				opCounter_ += 4;
			}
		}
		opCounter_++;
	}while(swaped);
	return;
}


void InsertionSort::sort(){
	opCounter_ = 0;
    int i,j,tmp;
    for (i = 1; i < size_; i++) {
        j = i;
        opCounter_++;
        while (j > 0 && dataField_[j - 1] > dataField_[j]) {
            tmp = dataField_[j];
            dataField_[j] = dataField_[j - 1];
            dataField_[j - 1] = tmp;
            j--;
            opCounter_ += 6;
        }
    }
}

void SelectionSort::sort(){
	opCounter_ = 0;
	bool swaped = false;
	int minPos, tmp;
	for(int i = 0; i < (size_ - 1); i++){
		minPos = i;
		opCounter_ += 3;
		for(int j = (i + 1); j < size_; j++){
			opCounter_++;
			if(dataField_[j] < dataField_[minPos]){
				minPos = j;
				swaped = true;
				opCounter_ += 2;
			}
		}
		opCounter_++;
		if(swaped){
			tmp = dataField_[i];
			dataField_[i] = dataField_[minPos];
			dataField_[minPos] = tmp;
			opCounter_+=3;
		}

	}
}

void MergeSort::sort(){
	opCounter_ = 0;
	return (mergeSort(0, 0, size_ - 1));
}
void MergeSort::mergeSort(int level, int l, int r){
	int m;

	// split, let it sort and merge
	if(l < r){
		// split
		m = l + ((r-l) / 2);
		opCounter_ += 2;

		// sort the sub-lists
		mergeSort(level+1,l,m );
		mergeSort(level+1,m+1,r);

		//merge the sorted sub-lists [l,m] with [m+1,r]
		merge(l, m, r);
	}
	return;
}

// merge two sorted list
// the lists are defined as [l,m] and [m+1,r]
// data are stored the member dataField_
void MergeSort::merge(int l, int m, int r){
	int tmpSize = (r-l) + 1;
	int tmpList[tmpSize];

	int tmpListIdx = 0;
	int lIdx = l;
	int rIdx = m+1;

	opCounter_ += 5;

	while((lIdx <= m) && (rIdx <= r)){
		opCounter_ += 5;
		if( dataField_[lIdx] < dataField_[rIdx]){
			tmpList[tmpListIdx] = dataField_[lIdx];
			lIdx++;
			opCounter_ +=2;
		}else{
			tmpList[tmpListIdx] = dataField_[rIdx];
			rIdx++;
			opCounter_ +=2;
		}
		tmpListIdx++;

	}

	opCounter_++;
	while(lIdx <= m){
		tmpList[tmpListIdx] = dataField_[lIdx];
		lIdx++;
		tmpListIdx++;
		opCounter_ += 3;
	}

	opCounter_++;
	while(rIdx <= r){
		tmpList[tmpListIdx] = dataField_[rIdx];
		rIdx++;
		tmpListIdx++;
		opCounter_ += 3;
	}

	for(int i=0; i < tmpSize; i++){
		opCounter_ += 2;
		dataField_[l + i] = tmpList[i];
	}
	return;
}

template<typename T>
DataItem<T>::DataItem(string name){
	typeName_ = name;
}

template<typename T>
T DataItem<T>::get(){
	return value_;
};

template<typename T>
void DataItem<T>::set(T value){
	value_ = value;
};

template<typename T>
string DataItem<T>::toString(){
	stringstream ss;
	ss << value_;
	return ss.str();
};

template<typename T>
string DataItem<T>::toXmlString(){
	stringstream ss;
	ss << "<" << typeName_ << ">";
	ss << toString();
	ss << "</" << typeName_ << ">";
	return ss.str();
};



ostream &operator<< (ostream &ostr, const advComplNmb &rhs){
	DataItem<float> re("real");
	DataItem<float> im("imaginary");

	re.set(rhs.re_);
	im.set(rhs.im_);

	ostr << re.toXmlString() <<  im.toXmlString();
	return ostr;
}


void P3A00(){

	int n = 5;
	ICreature *creatureList[n];
	ICreatureFactory *factory;
	CreatureFactory specificFactory;

	factory = &specificFactory;

	for(int i=0; i < n; i++){
		creatureList[i] = factory->produceCreatureRandomly();
	}


	for(int i=0; i < n; i++){
		cout << i+1 << ". creature: ";
		cout << "I am a "          << creatureList[i]->name();
		cout << " eating "         << creatureList[i]->eats();
		cout << " while saying:\"" << creatureList[i]->says() << "\"" << endl;
	}
}

void P3A01(){
	P3::IListOfNumbers *ptrList;
	P3::SortAndShuffle l;
	P3::MergeSort  m;

	ptrList = &m;

	ptrList->init(7);

	for(int i = 0; i < 7; i++){
		ptrList->shuffle();
		cout << "unsorted:";
		ptrList->out();
		cout << endl;

		ptrList->sort();
		cout << "sorted  :";
		ptrList->out();
		cout << endl << endl;
	}
	return;
}



void P3A02(){
	P3::DataItem<float> fltV("float");
	P3::DataItem<int> intV;
	P3::DataItem<bool> boolV("bool");
	P3::DataItem<char> charV("char");
	P3::DataItem<string> stringV("string");

	fltV.set(102);
	intV.set(-23);
	boolV.set(false);
	stringV.set("Hello World!");
	charV.set('[');
	advComplNmb complexNmb;
	complexNmb.re(1.2);
	complexNmb.im(0.8);

	cout << "<xml>\n";
	cout << intV.toXmlString() << endl;
	cout << fltV.toXmlString() << endl;
	cout << boolV.toXmlString() << endl;
	cout << charV.toXmlString() << endl;
	cout << stringV.toXmlString() << endl;
	cout << "</xml>\n";
}


void P3A03(){
	P3::DataItem<float> fltV("float");
	P3::DataItem<int> intV;
	P3::DataItem<bool> boolV("bool");
	P3::DataItem<advComplNmb> cN("complexNmb");
	P3::DataItem<char> charV("char");
	P3::DataItem<string> stringV("string");

	fltV.set(102);
	intV.set(-23);
	boolV.set(false);
	stringV.set("Hello World!");
	charV.set('[');
	advComplNmb complexNmb;
	complexNmb.re(1.2);
	complexNmb.im(0.8);

	cN.set(complexNmb);

	cout << "<xml>\n";
	cout << intV.toXmlString() << endl;
	cout << fltV.toXmlString() << endl;
	cout << boolV.toXmlString() << endl;

	cout << charV.toXmlString() << endl;
	cout << stringV.toXmlString() << endl;

	cout << cN.toXmlString() << endl;
	cout << "</xml>\n";
}

void P3A04(){
	P3::SortAndShuffle bubbleSort;
	P3::InsertionSort  insertionSort;
	P3::SelectionSort  selectionSort;
	P3::MergeSort      mergeSort;

	for(long int i = 1; i <= 1000; i=i+1){
		bubbleSort.init(i);
		insertionSort.init(i);
		selectionSort.init(i);
		mergeSort.init(i);


		bubbleSort.shuffle();
		insertionSort.shuffle();
		mergeSort.shuffle();
		selectionSort.shuffle();

		/*
		bubbleSort.out(); cout << endl;
		insertionSort.out(); cout << endl;
		mergeSort.out(); cout << endl;


		cout << "n = "<< i << ":\t";
		bubbleSort.sort();
		cout << "bubble: " << bubbleSort.getOpCounter() << "\t";
		insertionSort.sort();
		cout << "insert: " << insertionSort.getOpCounter() << "\t";
		mergeSort.sort();
		cout << "merge:  " << mergeSort.getOpCounter() << "\t";
		cout << endl;


		bubbleSort.out(); cout << endl;
		insertionSort.out(); cout << endl;
		mergeSort.out(); cout << endl;
		cout << endl << endl << endl;
		*/

		cout << i << "\t";
		bubbleSort.sort();
		cout << bubbleSort.getOpCounter() << "\t" ;
		//insertionSort.sort();
		//cout << insertionSort.getOpCounter() << "\t";
		selectionSort.sort();
		cout << selectionSort.getOpCounter() << "\t";
		mergeSort.sort();
		cout << mergeSort.getOpCounter() << "\t";
		cout << endl;


	}

	return;
}

}
