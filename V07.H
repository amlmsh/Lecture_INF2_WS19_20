/*
 * V07.H
 *
 *  Created on: 23.06.2018
 *      Author: aml
 */

#ifndef V07_H_
#define V07_H_

#include <cstddef>
#include <iostream>

using namespace std;

namespace V07 {

template<typename T>
class Element;

template<typename T>
class Element {
public:
	Element<T> *nextElem_ = NULL;
	T value_;
};


template<typename T>
class List {
public:

	virtual void prepend(T value){
		Element<T> *tmp = new Element<T>;
		tmp->value_ = value;
		tmp->nextElem_ = ptrHead_;
		ptrHead_ = tmp;
		return;
	}

	virtual void append (T value){
		if(isEmpty()){
			prepend(value);
			return;
		}

		Element<T> *ptrElem = ptrHead_;
		Element<T> *tmp = new Element<T>;
		tmp->nextElem_ = NULL;
		tmp->value_ = value;

		// go to the end
		while ((ptrElem->nextElem_) != NULL) {
			ptrElem = ptrElem->nextElem_;
		}
		ptrElem->nextElem_ = tmp;

		return;
	}


	virtual T removeFirst(){
		if (isEmpty()) {
			throw string("list is empty");
		}
		Element<T> *ptrElem = ptrHead_;
		T tmp;
		ptrHead_ = ptrElem->nextElem_;
		tmp = ptrElem->value_;
		delete ptrElem;
		return tmp;
	};

	virtual T removeLast (){
		// 1st case queue empty
		if (ptrHead_ == NULL) {
			throw string("list is empty");
		}

		T tmp;
		// 2nd case queue contains only one element
		if ((ptrHead_)->nextElem_ == NULL) {
			tmp = (ptrHead_)->value_;
			delete (ptrHead_);
			ptrHead_ = NULL;
			return tmp;
		}

		Element<T> *ptrElem = ptrHead_;
		Element<T> *ptrLast;

		// go to the end
		while ((ptrElem->nextElem_)->nextElem_ != NULL) {
			ptrElem = ptrElem->nextElem_;
		}
		// ptrElement refers to the element before the last
		ptrLast = ptrElem->nextElem_;
		tmp = ptrLast->value_;
		delete ptrLast;
		ptrElem->nextElem_ = NULL;
		return tmp;
	};

	virtual bool isEmpty(){
		return(ptrHead_ == NULL);
	};

	void print(){
		Element<T> *ptrElem;
		cout << "[";
		ptrElem = ptrHead_;
		while (ptrElem != NULL) {
			cout << ptrElem->value_;
			ptrElem = ptrElem->nextElem_;
			if (ptrElem != NULL) {
				cout << ", ";
			}
		}
		cout << "]";
		cout.flush();
	};

protected:
	Element<T> *ptrHead_ = NULL;
};


template<typename T>
class ISet {
public:
	virtual T out() = 0;
	virtual void in(T element) = 0;
	virtual void print() = 0;
	virtual bool isEmpty() = 0;
};

template<typename T>
class Set: public ISet<T> {
protected:
	Element<T> *head_;

public:
	Set() {
		head_ = NULL;
	}
	virtual ~Set() {
		Element<T> *tmp;
		tmp = head_;
		while (tmp != NULL) {
			head_ = tmp->nextElem_;
			delete tmp;
			tmp = head_;
		}
	}

	virtual bool isEmpty() {
		return (head_ == NULL);
	}

	virtual void in(T value) {
		Element<T> *tmp = new Element<T>;
		tmp->nextElem_ = head_;
		tmp->value_ = value;
		head_ = tmp;
	}

	virtual T out() = 0;

	virtual void print() {
		Element<T> *ptrElem;
		cout << "[";
		ptrElem = head_;
		while (ptrElem != NULL) {
			cout << ptrElem->value_;
			ptrElem = ptrElem->nextElem_;
			if (ptrElem != NULL) {
				cout << ", ";
			}
		}
		cout << "]";
		cout.flush();
	}
};

template<typename T>
class Stack: public Set<T> {
public:
	Stack() :
			Set<T>() {
		;
	}
	;

	/*
	 * Remove element from head_
	 */
	T out() {
		if (this->head_ == NULL) {
			throw string("stack is empty");
		}
		Element<T> *ptrElem = this->head_;
		T tmp;
		this->head_ = ptrElem->nextElem_;
		tmp = ptrElem->value_;
		delete ptrElem;
		return tmp;
	}

};

template<typename T>
class Queue: public Stack<T> {
public:
	Queue() :
			Stack<T>() {
		;
	}
	;

	/*
	 * Remove element from tail (e.g. the last element)
	 */
	T out() {
		// 1st case queue empty
		if (this->head_ == NULL) {
			throw string("queue is empty");
		}

		T tmp;
		// 2nd case queue contains only one element
		if ((this->head_)->nextElem_ == NULL) {
			tmp = (this->head_)->value_;
			delete (this->head_);
			this->head_ = NULL;
			return tmp;
		}

		Element<T> *ptrElem = this->head_;
		Element<T> *ptrLast;

		// go to the end
		while ((ptrElem->nextElem_)->nextElem_ != NULL) {
			ptrElem = ptrElem->nextElem_;
		}
		// ptrElement refers to the element before the last
		ptrLast = ptrElem->nextElem_;
		tmp = ptrLast->value_;
		delete ptrLast;
		ptrElem->nextElem_ = NULL;
		return tmp;
	}

};

class TestStack {
	bool unitTest0();
	bool unitTest1();
	bool unitTest2();
	bool unitTest3();
	bool unitTest4();

public:
	TestStack() {
	}
	;
	void test() {

		if (unitTest0()) {
			cout << ".";
		} else {
			cout << "error unitTest0\n";
			return;
		}
		cout.flush();

		if (unitTest1()) {
			cout << ".";
		} else {
			cout << "error unitTest1\n";
			return;
		}
		cout.flush();

		if (unitTest2()) {
			cout << ".";
		} else {
			cout << "error unitTest2\n";
			return;
		}
		cout.flush();

		if (unitTest3()) {
			cout << ".";
		} else {
			cout << "error unitTest3\n";
			return;
		}
		cout.flush();

		if (unitTest4()) {
			cout << ".";
		} else {
			cout << "error unitTest4\n";
			return;
		}
		cout.flush();

		cout << endl;
		cout.flush();
	}
};

class TestQueue {
	bool unitTest0();
	bool unitTest1();
	bool unitTest2();
	bool unitTest3();
	bool unitTest4();

public:
	TestQueue() {
	}
	;
	void test() {
		if (unitTest0()) {
			cout << ".";
		} else {
			cout << "error unitTest0\n";
			return;
		}
		cout.flush();

		if (unitTest1()) {
			cout << ".";
		} else {
			cout << "error unitTest1\n";
			return;
		}
		cout.flush();

		if (unitTest2()) {
			cout << ".";
		} else {
			cout << "error unitTest2\n";
			return;
		}
		cout.flush();

		if (unitTest3()) {
			cout << ".";
		} else {
			cout << "error unitTest3\n";
			return;
		}
		cout.flush();

		if (unitTest4()) {
			cout << ".";
		} else {
			cout << "error unitTest4\n";
			return;
		}
		cout.flush();

		cout << endl;
		cout.flush();
	}
};



class TestList {
	bool unitTest0();
	bool unitTest1();
	bool unitTest2();
	bool unitTest3();
	bool unitTest4();

public:
	TestList() {
	}
	;
	void test() {
		if (unitTest0()) {
			cout << ".";
		} else {
			cout << "error unitTest0\n";
			return;
		}
		cout.flush();

		if (unitTest1()) {
			cout << ".";
		} else {
			cout << "error unitTest1\n";
			return;
		}
		cout.flush();

		if (unitTest2()) {
			cout << ".";
		} else {
			cout << "error unitTest2\n";
			return;
		}
		cout.flush();

		if (unitTest3()) {
			cout << ".";
		} else {
			cout << "error unitTest3\n";
			return;
		}
		cout.flush();

		if (unitTest4()) {
			cout << ".";
		} else {
			cout << "error unitTest4\n";
			return;
		}
		cout.flush();

		cout << endl;
		cout.flush();
	}
};

}


void demoV07_00();


#endif /* V07_H_ */
