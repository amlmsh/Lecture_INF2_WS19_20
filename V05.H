/*
 * V05.H
 *
 *  Created on: 13.06.2018
 *      Author: aml
 */

#ifndef V05_H_
#define V05_H_

#include <iostream>
using namespace std;

namespace V05{


class complexNmb{
	float re_ = 0;
	float im_ = 0;
public:
	float re  ();
	float im  ();
	void  set (float re, float im);

	complexNmb operator-(complexNmb rhs);


	friend complexNmb      operator+(complexNmb lhs, complexNmb rhs);
	friend int             operator>(complexNmb lhs, complexNmb rhs);
	friend std::ostream & operator<<(std::ostream &lhs, complexNmb rhs);

};


//
// template function definition
//  must be put into the header
//  otherwise linking does not work
//  Many comples do not like having
//  template functions defined in
//   separate files
//

template <typename T>
class ISet{
public:
	virtual void out()    = 0;
	virtual void insert(T value) = 0;
	virtual void sort()   = 0;
	virtual void swap()   = 0;
};

template <typename T>
class Set : public ISet<T>{
	T *dataField_;
	int size_;
	int next_;

public:
	Set(int size = 1);
	~Set();
	Set<T>(const Set<T> &s);
	virtual void out();
	virtual void insert(T value);
	virtual void sort();
	virtual void swap();

	Set & operator=(const Set &rhs);

};


template <typename T>
Set<T>::Set(int size){
	try{
		if(size < 1){
			size = 1;
		}
		size_ = size;
		next_ = 0;
		dataField_ = new T[size_];
	}catch(...){
		size_ = 0;
		next_ = 0;
		dataField_ = NULL;
	}
}

template <typename T>
Set<T>::~Set(){
	if(size_ > 0){
		delete [] dataField_;
		size_ = 0;
		next_ = 0;
		dataField_ = NULL;
	}
}

template <typename T>
void Set<T>::out(){
	if(next_ == 0){
		cout << "[]";
		return;
	}

	cout << "[";
	for(int i=0; i < (next_ - 1); i++){
		cout << dataField_[i] << ", ";
	}
	cout << dataField_[next_- 1];
	cout << "]";
}

template <typename T>
void Set<T>::insert(T value){
	if(next_ < size_ ){
		dataField_[next_] = value;
		next_++;
	}else{
		throw string("Set is full.");
	}
}

template <typename T>
void Set<T>::sort(){
	bool swapped = false;
	T tmp;
	do{
		swapped = false;
		for(int i = 1; i < next_; i++){
			if(dataField_[i-1] > dataField_[i]){
				tmp = dataField_[i-1];
				dataField_[i-1] = dataField_[i];
				dataField_[i] = tmp;
				swapped = true;
				break;
			}
		}

	}while(swapped);
}

template <typename T>
void Set<T>::swap(){
	int z;
	T tmp;
	for(int i=0; i < next_; i++){
		z = rand() % next_;
		tmp = dataField_[i];
		dataField_[i] = dataField_[z];
		dataField_[z] = tmp;
	}
}

template <typename T>
 Set<T>::Set(const Set<T> &s){
	cout << "\ncopy constructor\n\n";

	try{
		this->dataField_ = new T[s.size_];
		this->size_ = s.size_;
		this->next_ = s.next_;

		for(int i=0; i<next_; i++){
			this->dataField_[i] = s.dataField_[i];
		}

	}catch(...){
		size_ = 0;
		next_ = 0;
		dataField_ = NULL;
	}
}


template <typename T>
Set<T> & Set<T>::operator=(const Set<T> &rhs){
	cout << "\nassignment constructor\n\n";
	if(this == &rhs){
		return *this;
	}

	try{
		this->size_ != 0;
		delete [] dataField_;

		this->dataField_ = new T[rhs.size_];
		this->size_ = rhs.size_;
		this->next_ = rhs.next_;

		for(int i=0; i<next_; i++){
			this->dataField_[i] = rhs.dataField_[i];
		}

	}catch(...){
		size_ = 0;
		next_ = 0;
		dataField_ = NULL;
	}

	return *this;

}



}




void demoV05_overloading();

void demoV05_templateList();

void demoV05_AssignmentEtc();


#endif /* V05_H_ */
