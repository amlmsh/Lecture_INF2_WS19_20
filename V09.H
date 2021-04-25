/*
 * V09.H
 *
 *  Created on: 01.07.2018
 *      Author: aml
 */

#ifndef V09_H_
#define V09_H_

#include <fstream>
#include <string>

#include "V08.H"

using namespace std;

/**
 *
 * namespace
 *
 * unit testing structure
 *
 * \brief implements a framework for unit testing
 *
 */
namespace V09{

class ITestItem{
public:
	virtual void   testExecution()              = 0;
	virtual bool   getResult()                  = 0;
	virtual string getName()                    = 0;
	virtual string toXmlStr()                   = 0;
	virtual void   addTestItem(ITestItem *item) = 0;
};


class TestItem : public ITestItem{
public:
	TestItem(string s = string("undefined test item")){name_ = s; result_ = false;};
	virtual string getName(){ return name_;};
	virtual bool   getResult(){return result_;};
	virtual void   addTestItem(ITestItem *item) {throw "TestItem cannot add TestItem\n";};
protected:
	string name_;
	bool   result_ = false;
};


class TestCase : public TestItem{
public:
	TestCase(string s = string("undefined test case")) : TestItem(s){};

	void testExecution(){
		result_ = testRun();
	}

	string toXmlStr(){
		string s("");
		s += "<TestCase name=\"" + getName() + "\">";
		if(result_){
			s += "PASSED";
		}else{
			s += "FAILED";
		};
		s += "</TestCase>";

		return s;
	}
protected:
	virtual bool testRun(){
		return false;
	}

};


class TestSuite : public TestItem{
public:
	TestSuite(string s = string("undefined test suite")) : TestItem(s){

	};

	virtual void testExecution(){
		result_ = true;
		TestItem *ptrTC;
		V08::Queue<TestItem*> tmpTC;
		while(!testItems_.isEmpty()){
			ptrTC = testItems_.dequeue();
			ptrTC->testExecution();
			result_ = result_ && ptrTC->getResult();
			tmpTC.enqueue(ptrTC);
		}

		while(!tmpTC.isEmpty()){
			ptrTC = tmpTC.dequeue();
			testItems_.enqueue(ptrTC);
		}
	};

	virtual string  toXmlStr(){
		string s("");
		s += "<" + this->testType_ + " name=\"" + this->name_   + "\" status=\"";
		if(getResult()){
			s += "PASSED\">";
		}else{
			s += "FAILED\">";
		}

		TestItem *ptrTC;
		V08::Queue<TestItem*> tmpTC;
		while(!testItems_.isEmpty()){
			ptrTC = testItems_.dequeue();
			s += ptrTC->toXmlStr();
			tmpTC.enqueue(ptrTC);
		}

		while(!tmpTC.isEmpty()){
			ptrTC = tmpTC.dequeue();
			testItems_.enqueue(ptrTC);
		}

		s += "</" + testType_ + ">";

		return s;
	}

	virtual void   addTestItem(TestItem *tc) {
		testItems_.enqueue(tc);
	};

protected:
	V08::Queue<TestItem *> testItems_;
	string testType_ = "TestSuite";
};


class UnitTest : public TestSuite{
public:
	UnitTest(string s = "undefined unit test") : TestSuite(s){
		testType_ = "UnitTest";
	};

	void writeResultsToFile(string fileName){
		std::ofstream file(fileName);
		file <<  toXmlStr();
		file.close();
		return;
	}

};




} // namespace V09

void demoV09_TestList();

#endif /* V09_H_ */
