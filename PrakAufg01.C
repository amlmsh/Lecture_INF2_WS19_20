/*
 * PrakAufg01.C
 *
 *  Created on: 27.04.2018
 *      Author: aml
 */


#include "PrakAufg01.H"

#include <iostream>
#include <sstream>

using namespace std;

namespace SemesterProgramming{

CharStack::CharStack(int size){
	this->size_ = 0;
	this->dataField_ = NULL;
	this->idxLastElement_ = -1;
	this->init(size);
}

CharStack::~CharStack(){
	this->clear();
}

void CharStack::init(int size){
	// if memory is allocated, free it
	if(this->size_ > 0){
		delete  [] this->dataField_;
		this->size_ = 0;
		this->dataField_ = NULL;
		this->idxLastElement_ = -1;
	}

	// if requested memory size is not zero or less
	if(size > 0){
		  try{
			  this->dataField_ = new char[size];
			  this->size_ = size;
			  this->idxLastElement_ = -1;
		  }catch (std::bad_alloc& ba){
				this->size_ = 0;
				this->dataField_ = NULL;
				this->idxLastElement_ = -1;
		  }
	}else{ // otherwise keep stack empty
		this->size_ = 0;
		this->dataField_ = NULL;
		this->idxLastElement_ = -1;
	}

}
void CharStack::clear(){
	if(this->size_ != 0){
		delete [] this->dataField_;
		this->size_ = 0;
		this->idxLastElement_ = -1;
	}
}

bool CharStack::isEmpty(){
	if(this->size_ < 1){
		return true;
	};

	if(this->idxLastElement_ < 0){
		return true;
	}else{
		return false;
	}


}
bool CharStack::isFull(){
	if(this->size_ < 1) return true;
	if(this->idxLastElement_ < (this->size_ - 1)){
		return false;
	}else{
		return true;
	}
}

int  CharStack::size(){
	return size_;
}

char CharStack::pop(){
	if(! this->isEmpty()){
		this->idxLastElement_--;
		return dataField_[idxLastElement_ + 1];
	}else{
		throw string("pop failed due to empty stack.");
	}
}

bool CharStack::push(char c){
	if(! this->isFull()){
		this->idxLastElement_++;
		this->dataField_[idxLastElement_] = c;
		return true;
	}else{
		return false;
	}
}

char CharStack::peek(){
	if(! this->isEmpty()){
		return dataField_[this->idxLastElement_];
	}else{
		throw string("peek failed due to empty stack.");
	}
}

/*
 *
 * Implementation of class SymbolNumber
 *
 */

NumberStack::NumberStack(string s){

	if(s.length() == 0){
		this->init(1);
		this->push('0');
		return;
	};


	// read  digit elements of char
	this->init(s.length());
	char tmp;

	for(int i=0; i < s.length() ; i++){
		tmp = s[i];
		if( (tmp >= '0') && (tmp <= '9') ){
			if(! ((tmp == '0') && (this->isEmpty()))){
				this->push(tmp);
			}
		}else{
			break;
		}
	};

	return;
}

NumberStack::NumberStack(NumberStack *nmbStack){
	if(nmbStack == NULL){
		this->init(1);
		this->push('0');
		return;
	}

	CharStack *tmpStack = new CharStack();
	tmpStack->init(nmbStack->size());
	while(!nmbStack->isEmpty()){
		tmpStack->push(nmbStack->pop());
	}

	char tmpChar;
	this->init(nmbStack->size());
	while(!tmpStack->isEmpty()){
		tmpChar = tmpStack->pop();
		this->push(tmpChar);
		nmbStack->push(tmpChar);
	}

	return;
}

NumberStack::~NumberStack(){
	this->clear();
}

int NumberStack::size(){
	return (CharStack::size());
}

NumberStack *NumberStack::add(NumberStack *opStack){
	NumberStack *finalResStack = new NumberStack();
	// create copies of the operands
	NumberStack *tmpOp1Stack = new NumberStack(this);
	NumberStack *tmpOp2Stack = new NumberStack(opStack);
	NumberStack *tmpResStack = new NumberStack();

	if(tmpOp2Stack->size() > tmpOp1Stack->size()){
		tmpResStack->init(tmpOp2Stack->size() + 1);
	}else{
		tmpResStack->init(tmpOp1Stack->size() + 1);
	}

	char op1Digit, op2Digit, resDigit, tmpChar;
	int uebertragValue;
	uebertragValue = 0;

	while(!(tmpOp1Stack->isEmpty()  &&  tmpOp2Stack->isEmpty() && !uebertragValue)){
		try{
			op1Digit = '0';
			op2Digit = '0';
			if(!tmpOp1Stack->isEmpty()){
				op1Digit = tmpOp1Stack->pop();
			}
			if(!tmpOp2Stack->isEmpty()){
				op2Digit = tmpOp2Stack->pop();
			};

			resDigit = (op1Digit - '0') + (op2Digit - '0') + uebertragValue;

			if(resDigit > 9){
				resDigit = resDigit - 10;
				uebertragValue = 1;
			}else{
				uebertragValue = 0;
			}

			resDigit = resDigit + '0';

			tmpResStack->push(resDigit);
		}catch(string s){
			cout << "error: " << s;
			exit(0);
		}
		catch(...){
			cout << "unknown error.";
			exit(0);
		};
	}

	// invert stack again
	finalResStack->init(tmpResStack->size() + 1);
	while(!tmpResStack->isEmpty()){
		tmpChar = tmpResStack->pop();
		finalResStack->push(tmpChar);

	}

	tmpOp1Stack->clear();
	tmpOp2Stack->clear();
	tmpResStack->clear();

	return finalResStack;
}


string NumberStack::toStr(){
	stringstream ss;
	string str = "";

	if(this->isEmpty()){
		return string("0");
	}

	char tmpChar;
	NumberStack *tmpStack = new NumberStack(this);
	NumberStack *outStack = new NumberStack(tmpStack);

	outStack->init(tmpStack->size());

	while(!tmpStack->isEmpty()){
		tmpChar = tmpStack->pop();
		outStack->push(tmpChar);

	}

	// put the elements back into the stack
	while(!outStack->isEmpty()){
		tmpChar = outStack->pop();
		ss << tmpChar;
	}
	ss >> str;

	delete tmpStack;
	delete outStack;

	return str;
}

int NumberStack::sizeNumber(){
	int counter = 0;

	CharStack *tmpStack = new CharStack();
	tmpStack->init(this->size());

	// empty the stack and count
	while(!this->isEmpty()){
		tmpStack->push(this->pop());
		counter++;
	}

	// put the elements back into the stack
	//  don't count
	while(!tmpStack->isEmpty()){
		this->push(tmpStack->pop());
	}

	tmpStack->clear();

	return counter;
}

/**
 *
 * Test class implementation
 *
 *
 */



TestCharStack::TestCharStack(ICharStack *stack){
	testStack_  = stack;
};

bool TestCharStack::runTest(){

	bool testResult = true;

	try{
		if(!testConstructor("testConstructor")) throw string("testConstructor");
		if(!testInitSize("testInitSize")) throw string("testInitSize");
		if(!testInitClear("testInitClear")) throw string("testInitClear");
		if(!testIsEmpty("testEmpty")) throw string("testEmpty");
		if(!testIsFull("testFull")) throw string("testFull");
		if(!testPopPush("testPopPush")) throw string("testPopPush");
		if(!testPeek("testPeek")) throw string("testPeek");


	}catch(string msg){
		cout << "\n\nTest not successful, see error " << msg << std::endl;
		exit(0);
	}catch(...){
		cout << "\n\nUnknown error " << std::endl;
		exit(0);
	}

	cout << "\nAll Tests successul passed.\n";
}

bool TestCharStack::testConstructor(string testName){
	if(testStack_->size() != 100){
		cout << "Error: " << testName << " constructed size != 100.\n";
		return false;
	}
	cout << ".";
	return true;
}

bool TestCharStack::testInitClear(string testName){
	int s = 123;

	testStack_->clear();
	if(testStack_->size() != 0){
		cout << "Error: " << testName << " with clear-sate "<<  "init.\n";
		return false;
	}
	cout << ".";

	testStack_->init(123);
	if(testStack_->size() == 0){
		cout << "Error: " << testName << " with non-clear-sate "<<  "init.\n";
		return false;
	}
	cout << ".";

	testStack_->clear();
	if(testStack_->size() != 0){
		cout << "Error: " << testName << " with clear-sate "<<  "init.\n";
		return false;
	}
	cout << ".";

	// multiple clear
	testStack_->clear();
	testStack_->clear();
	testStack_->clear();
	if(testStack_->size() != 0){
		cout << "Error: " << testName << " with clear-sate "<<  "init.\n";
		return false;
	}
	cout << ".";


	// multiple inits and clears
	try{
		for(int i=10; i < 100000; i++){
			testStack_->clear();
			testStack_->init(i*100);
		}
	}catch(...){
		cout << "Error: " << testName << " multiple clear-inits\n";
		return false;
	}
	cout << ".";

	// multiple inits and clears
	testStack_->clear();
	try{
		for(int i=10; i < 100000; i++){
			testStack_->init(i*100);
		}
	}catch(...){
		cout << "Error: " << testName << " multiple clear-inits\n";
		return false;
	}
	cout << ".";


	return true;
}



bool TestCharStack::testInitSize(string testName){
	int s = 123;


	testStack_->init(-1);
	if(testStack_->size() != 0){
		cout << "Error: " << testName << " with -1 init.\n";
		return false;
	}
	cout << ".";


	testStack_->init(0);
	if(testStack_->size() != 0){
		cout << "Error: " << testName << " with 0 init.\n";
		return false;
	}
	cout << ".";

	// multiple zero initializations
	testStack_->init(0);
	testStack_->init(-1);
	testStack_->init(0);
	if(testStack_->size() != 0){
		cout << "Error: " << testName << " with multiple 0 -1 init.\n";
		return false;
	}
	cout << ".";



	testStack_->init(1);
	testStack_->init(10);
	testStack_->init(20);
	testStack_->init(300);
	testStack_->init(5000);
	testStack_->init(199999);
	testStack_->init(123456789);
	if(testStack_->size() < 1){
		cout << "Error: " << testName << " with " << s <<"  multiple non-zero-init.\n";
		return false;
	}
	cout << ".";



	testStack_->init(s);
	if(testStack_->size() != s){
		cout << "Error: " << testName << " with " << s <<"  init.\n";
		return false;
	}
	cout << ".";

	testStack_->init(s);
	if(testStack_->size() != s){
		cout << "Error: " << testName << " with " << s <<"  init.\n";
		return false;
	}
	cout << ".";

	long long int S = 99999999;
	testStack_->init(S);
	if(testStack_->size() != S){
		cout << "Error: " << testName << " with " << S <<"  init.\n";
		return false;
	}
	cout << ".";

	return true;
}


bool TestCharStack::testIsEmpty(string testName){

	testStack_->clear();
	if(!testStack_->isEmpty()){
		cout << "Error: " << testName << " with 1.empty state.\n";
		return false;
	}
	cout << ".";



	testStack_->init(123);
	testStack_->clear();
	if(!testStack_->isEmpty()){
		cout << "Error: " << testName << " with 2. empty state.\n";
		return false;
	}
	cout << ".";

	return true;

	testStack_->init(123);
	testStack_->init(-123);
	if(!testStack_->isEmpty()){
		cout << "Error: " << testName << " with 3. empty state.\n";
		return false;
	}
	cout << ".";

	testStack_->init(123);
	if(testStack_->isEmpty()){
		cout << "Error: " << testName << " with non-empty state.\n";
		return false;
	}
	cout << ".";

	return true;
}


bool TestCharStack::testIsFull(string testName){
	testStack_->clear();

	for(int i=1; i < 123; i++){
		testStack_->clear();
		testStack_->init(i);
		for(int c=0; c < i; c++){
			testStack_->push('X');
		}
		if(!testStack_->isFull()){
			cout << "Error: " << testName << " with full state "<< i << ".\n";
			return false;
		}
	}
	cout << ".";

	for(int i=1; i < 123; i++){
		testStack_->clear();
		testStack_->init(i);
		for(int c=0; c < (i-1); c++){
			testStack_->push('X');
		}
		if(testStack_->isFull()){
			cout << "Error: " << testName << " with non-full state "<< i << ".\n";
			return false;
		}
	}
	cout << ".";

	// after a clear the stack shall be full, meaning
	//  no element can be stored since no memory is
	//  allocated, after clear
	testStack_->clear();
	if(!testStack_->isFull()){
		cout << "Error: " << testName << " with cleared-state.\n";
		return false;
	}
	cout << ".";

	// after a clear the stack shall be full, meaning
	//  no element can be stored since no memory is
	//  allocated, after clear
	testStack_->init(12);
	testStack_->clear();
	if(!testStack_->isFull()){
		cout << "Error: " << testName << " with cleared-after-init-state.\n";
		return false;
	}
	cout << ".";

	// after an init  the stack shall be full, meaning
	//  no element can be stored since no memory is
	//  allocated, after clear
	testStack_->init(12);
	testStack_->clear();
	testStack_->init(32);
	if(testStack_->isFull()){
		cout << "Error: " << testName << " with init-state.\n";
		return false;
	}
	cout << ".";

	return true;
}


bool TestCharStack::testPopPush(string testName){
	testStack_->clear();

	// after n push- followed by n pop-operations
	// the stack shall be empty
	for(int i=1; i < 123; i++){
		testStack_->clear();
		testStack_->init(i);
		for(int c=0; c < i; c++){
			testStack_->push('X');
		}
		for(int c=0; c < i; c++){
			testStack_->pop();
		}

		if(!testStack_->isEmpty()){
			cout << "Error: " << testName << " with empty-push-pop-state "<< i << ".\n";
			return false;
		}
	}
	cout << ".";

	// after n push- followed by n-1 pop-operations
	// the stack shouldn't be empty
	for(int i=1; i < 123; i++){
		testStack_->clear();
		testStack_->init(i);
		for(int c=0; c < i; c++){
			testStack_->push('X');
		}
		for(int c=0; c < i-1; c++){
			testStack_->pop();
		}

		if(testStack_->isEmpty()){
			cout << "Error: " << testName << " with non-empty-push-pop-state "<< i << ".\n";
			return false;
		}
	}
	cout << ".";


	testStack_->clear();
	testStack_->init(1);
	testStack_->push('X');
	if(testStack_->push('X')){
		cout << "Error: " << testName << " with push-full-state "<< ".\n";
	}
	cout << ".";

	testStack_->clear();
	if(testStack_->push('X')){
		cout << "Error: " << testName << " with push-uninitialised-state "<< ".\n";
	}
	cout << ".";



	testStack_->clear();
	testStack_->init(5);
	testStack_->push('0');
	if(testStack_->isEmpty()){
		cout << "Error: " << testName << " with not-empty-state "<< ".\n";
	}
	cout << ".";

	return true;
}


bool TestCharStack::testPeek(string testName){
	testStack_->clear();
	try{
		testStack_->peek();
		cout << "Error: " << testName << " with peek-uninitialised-state "<< ".\n";
		return false;
	}catch(...){
		;;
	}
	cout << ".";

	testStack_->init(3);
	try{
		testStack_->peek();
		cout << "Error: " << testName << " with peek-emptyStack-state "<< ".\n";
		return false;
	}catch(...){
		;;
	}
	cout << ".";

	testStack_->init(3);

	testStack_->push('a');
	testStack_->push('b');
	testStack_->push('c');
	testStack_->peek();
	testStack_->peek();
	testStack_->peek();
	if (testStack_->peek() != 'c'){
		cout << "Error: " << testName << " with peek-element-state " << ".\n";
		return false;
	}
	cout << ".";

	testStack_->pop();
	testStack_->peek();
	testStack_->peek();
	testStack_->peek();
	if (testStack_->peek() != 'b'){
		cout << "Error: " << testName << " with peek-element-state " << ".\n";
		return false;
	}
	cout << ".";

	testStack_->pop();
	testStack_->peek();
	testStack_->peek();
	testStack_->peek();
	if (testStack_->peek() != 'a'){
		cout << "Error: " << testName << " with peek-element-state " << ".\n";
		return false;
	}
	cout << ".";


	return true;
}


} // end namespace SemesterProgramming
