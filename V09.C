/*
 * V09.C
 *
 *  Created on: 01.07.2018
 *      Author: aml
 */

#include "V09.H"


/**
 *
 * \brief unit tests for List<T>
 *
 *
 */
namespace V10{

using namespace V09;

class TC13 : public TestCase{
	TC13() : TestCase(){};
public:
	TC13(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;
		int output;
		l.prepend(-1);
		l.prepend(0);
		l.prepend(1);

		try{
			output = l.removeLast();
			if(output == -1){
				;;
			}else{
				return false;
			}

			output = l.removeLast();
			if(output == 0){
				;;
			}else{
				return false;
			}

			output = l.removeLast();
			if(output == 1){
				;;
			}else{
				return false;
			}

			return true;
		}catch(...){
			return false;
		}
	}
};

class TC12 : public TestCase{
	TC12() : TestCase(){};
public:
	TC12(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;
		int output;
		l.prepend(-1);
		l.prepend(0);
		l.prepend(1);

		try{
			output = l.removeFirst();
			if(output == 1){
				;;
			}else{
				return false;
			}

			output = l.removeFirst();
			if(output == 0){
				;;
			}else{
				return false;
			}

			output = l.removeFirst();
			if(output == -1){
				;;
			}else{
				return false;
			}

			return true;
		}catch(...){
			return false;
		}
	}
};

class TC11 : public TestCase{
	TC11() : TestCase(){};
public:
	TC11(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;
		int output;
		l.append(-1);
		l.append(0);
		l.append(1);

		try{
			output = l.removeLast();
			if(output == 1){
				;;
			}else{
				return false;
			}

			output = l.removeLast();
			if(output == 0){
				;;
			}else{
				return false;
			}

			output = l.removeLast();
			if(output == -1){
				;;
			}else{
				return false;
			}

			return true;
		}catch(...){
			return false;
		}
	}
};


class TC10 : public TestCase{
	TC10() : TestCase(){};
public:
	TC10(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;
		int output;
		l.append(-1);
		l.append(0);
		l.append(1);

		try{
			output = l.removeFirst();
			if(output == -1){
				;;
			}else{
				return false;
			}

			output = l.removeFirst();
			if(output == 0){
				;;
			}else{
				return false;
			}

			output = l.removeFirst();
			if(output == 1){
				;;
			}else{
				return false;
			}

			return true;
		}catch(...){
			return false;
		}
	}
};


class TC9 : public TestCase{
	TC9() : TestCase(){};
public:
	TC9(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;
		int input = 12331;
		int output;
		l.append(input);
		try{
			output = l.removeLast();
			if(input == output){
				return true;
			}else{
				return false;
			}
		}catch(...){
			return false;
		}
	}
};


class TC8 : public TestCase{
	TC8() : TestCase(){};
public:
	TC8(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;
		l.prepend(1);
		try{
			l.removeLast();
			return true;
		}catch(...){
			return false;
		}
	}
};

class TC7 : public TestCase{
	TC7() : TestCase(){};
public:
	TC7(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;

		try{
			l.removeLast();
			return false;
		}catch(string s){
			return true;
		}catch(...){
			return false;
		}
	}
};






class TC6 : public TestCase{
	TC6() : TestCase(){};
public:
	TC6(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;
		int input = 12331;
		int output;
		l.prepend(input);
		try{
			output = l.removeFirst();
			if(input == output){
				return true;
			}else{
				return false;
			}
		}catch(...){
			return false;
		}
	}
};


class TC5 : public TestCase{
	TC5() : TestCase(){};
public:
	TC5(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;
		l.append(1);
		try{
			l.removeFirst();
			return true;
		}catch(...){
			return false;
		}
	}
};

class TC4 : public TestCase{
	TC4() : TestCase(){};
public:
	TC4(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;

		try{
			l.removeFirst();
			return false;
		}catch(string s){
			return true;
		}catch(...){
			return false;
		}
	}
};

class TC1 : public TestCase{
	TC1() : TestCase(){};
public:
	TC1(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;

		try{
			if(l.isEmpty()){
				return true;
			}else{
				return false;
			}
		}catch(...){
			return false;
		}

	}
};

class TC2 : public TestCase{
	TC2() : TestCase(){};
public:
	TC2(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;

		try{
			l.append(1);

			if(l.isEmpty()){
				return false;
			}else{
				return true;
			}
		}catch(...){
			return false;
		}

	}
};

class TC3 : public TestCase{
	TC3() : TestCase(){};
public:
	TC3(string s) : TestCase(s){};
	virtual bool testRun(){
		V08::List<int> l;

		try{
			l.append(1);
			l.removeFirst();

			if(l.isEmpty()){
				return true;
			}else{
				return false;
			}
		}catch(...){
			return false;
		}

	}
};

}

void demoV09_TestList(){

	/**
	 * Test cases
	 *
	 */
	V10::TC1 tc1("isEmpty - empty List");
	V10::TC2 tc2("isEmpty - non empty List");
	V10::TC3 tc3("isEmpty - empty List again");

	V10::TC4 tc4("removeFirst - empty List");
	V10::TC5 tc5("removeFirst - non empty List");
	V10::TC6 tc6("removeFirst - compare result");

	V10::TC7 tc7("removeLast - empty List");
	V10::TC8 tc8("removeLast - non empty List");
	V10::TC9 tc9("removeLast - compare result");

	V10::TC10 tc10("append - removeFirst");
	V10::TC11 tc11("append - removeLast");

	V10::TC12 tc12("prepend - removeFirst");
	V10::TC13 tc13("prepend - removeLast");


	/**
	 *
	 * Test Suites
	 *
	 */
	V09::TestSuite tsIsEmpty("isEmpty");
	tsIsEmpty.addTestItem(&tc1);
	tsIsEmpty.addTestItem(&tc2);
	tsIsEmpty.addTestItem(&tc3);

	V09::TestSuite tsRemoveFirst("removeFirst");
	tsRemoveFirst.addTestItem(&tc4);
	tsRemoveFirst.addTestItem(&tc5);
	tsRemoveFirst.addTestItem(&tc6);

	V09::TestSuite tsRemoveLast("removeLast");
	tsRemoveLast.addTestItem(&tc7);
	tsRemoveLast.addTestItem(&tc8);
	tsRemoveLast.addTestItem(&tc9);

	V09::TestSuite tsPrepend("Prepend");
	tsPrepend.addTestItem(&tc12);
	tsPrepend.addTestItem(&tc13);

	V09::TestSuite tsAppend("Append");
	tsAppend.addTestItem(&tc10);
	tsAppend.addTestItem(&tc11);


	/**
	 *
	 * unit test
	 *
	 */
	V09::UnitTest unit("V08::List");
	unit.addTestItem(&tsIsEmpty);
	unit.addTestItem(&tsRemoveFirst);
	unit.addTestItem(&tsRemoveLast);
	unit.addTestItem(&tsPrepend);
	unit.addTestItem(&tsAppend);

	unit.testExecution();
	unit.writeResultsToFile("out.xml");



}
