/*
 * PrakAufg02.C
 *
 *  Created on: 03.05.2018
 *      Author: aml
 */

/**
 *
 * \file PrakAufg02.C
 *
 * \brief Contains the implementation of class DataFieldInt.
 *
 */

#include <sstream>
#include <iostream>

#include "PrakAufg02.H"

namespace SemesterProgramming{

DataFieldDbl::DataFieldDbl(int wDim, int hDim) {
	ptrDataField_ = NULL;
	wDim_ = 0;
	hDim_ = 0;

	try{
		this->init(wDim,hDim);
		wDim_ = wDim;;
		hDim_ = hDim;
	}catch(std::invalid_argument &e){
		throw e;
	}catch(std::runtime_error &e){
		throw e;
	}catch(...){
		if(ptrDataField_ != NULL) {
			  delete [] ptrDataField_;
			  ptrDataField_ = NULL;
		  	  wDim_ = 0;
		  	  hDim_ = 0;
		  	  return;
		}
		std::runtime_error("Unknown error.");
	}
	wDim_ = wDim;
	hDim_ = hDim;

	return;
};

DataFieldDbl::~DataFieldDbl() {
	  if(ptrDataField_ != NULL){
		  delete [] ptrDataField_;
		  ptrDataField_ = NULL;
	  	  wDim_ = 0;
	  	  hDim_ = 0;
	  };
}
;

int DataFieldDbl::width() {
	return wDim_;
}
;

int DataFieldDbl::height() {
	return hDim_;
}
;

void DataFieldDbl::init(int wDim, int hDim) throw (std::invalid_argument,
		std::runtime_error) {
	if (ptrDataField_ != NULL) {
		throw std::runtime_error("Field already initialized.");
	};
	if (wDim < 1) {
		throw std::invalid_argument("w-dimension must larger 0.");
	};
	if (hDim < 1) {
		throw std::invalid_argument("h-dimension must larger 0.");
	};
	wDim_ = wDim;
	hDim_ = hDim;
	ptrDataField_ = new double[wDim*hDim];
	if (ptrDataField_ == NULL) {
		wDim_ = 0;
		hDim_ = 0;
		throw std::runtime_error("Got null pointer");
	}
}
;

void DataFieldDbl::set(int w, int h, double value) throw (out_of_range) {
	try {
		checkRange(w, h);
		setValue(glbIndex(w, h), value);
	} catch (std::out_of_range &e) {
		throw std::out_of_range(e.what());
	} catch (...) {
		throw std::out_of_range("Error while set-operation.");
	}
}
;
double DataFieldDbl::get(int w, int h)
		throw (std::out_of_range) {
	try {
		checkRange(w, h);
		return (getValue(glbIndex(w, h)));
	} catch (std::out_of_range &e) {
		throw std::out_of_range(e.what());
	} catch (...) {
		throw std::out_of_range("Error while get-operation.");
	}
}
int DataFieldDbl::glbIndex(int w, int h) throw (std::runtime_error) {
	return ((w * hDim_) + h);
}
;
void DataFieldDbl::checkRange(int w, int h) throw (std::out_of_range) {
	std::stringstream msg;

	if (ptrDataField_ == NULL) {
		msg << "Data Field is not initialized, call method init(...) first.";
		throw std::out_of_range(msg.str());
	}

	if ((w < 0) || (w > (wDim_ - 1))) {
		msg << "Index parameters w must be in the range [0, " << (wDim_ - 1)
				<< "] ";
		msg << "but w parameter is " << w << ".";
		throw std::out_of_range(msg.str());
	}
	if ((h < 0) || (h > (hDim_ - 1))) {
		msg << "Index parameters h must be in the range [0, " << (hDim_ - 1)
				<< "] ";
		msg << "but w parameter is " << h << ".";
		throw std::out_of_range(msg.str());
	}
};





void DataFieldDbl::setValue(int idx, double value) {
	ptrDataField_[idx] = value;
	return;
}

double DataFieldDbl::getValue(int idx) {
	return (ptrDataField_[idx]);
}


TestDataFieldDbl::TestDataFieldDbl(){
	;;
}


bool TestDataFieldDbl::runTest(){
	bool testResult = true;

	cout << "\nStart test.\n";
	cout.flush();

	try{
		if(!testInitSize1("testInitSize1")) throw string("testInitSize1");
		if(!testInitSize2("testInitSize2")) throw string("testInitSize2");
		if(!testInitSize3("testInitSize3")) throw string("testInitSize3");
		if(!testInitSize4("testInitSize4")) throw string("testInitSize4");
		if(!testInitSize5("testInitSize5")) throw string("testInitSize5");
		if(!testConstr("testInitConstr")) throw string("testConstr");
		if(!testRangeWidth("testRangeWidth")) throw string("testRangeWidth");
		if(!testRangeHeight("testRangeHeight")) throw string("testRangeHeight");
		if(!testSetGet("testSetGet")) throw string("testSetGet");
		if(!testSetGet1("testSetGet1")) throw string("testSetGet1");
		if(!testSetGet2("testSetGet2")) throw string("testSetGet2");
		if(!testSetGet3("testSetGet3")) throw string("testSetGet3");
		if(!testSetGet4("testSetGet4")) throw string("testSetGet4");
		if(!testSetGet5("testSetGet5")) throw string("testSetGet5");
		if(!testSetGet6("testSetGet6")) throw string("testSetGet6");
	}catch(string msg){
		cout << "\n\nTest not successful, see error " << msg << std::endl;
		exit(0);
	}catch(...){
		cout << "\n\nUnknown error " << std::endl;
		exit(0);
	}

	cout << "\nAll Tests successul passed.\n";
}



bool TestDataFieldDbl::testConstr(string testName){
	int w = 123;
	int h = 321;



	DataFieldDbl *testDataFieldDbl = new  DataFieldDbl(w,h);
	if((testDataFieldDbl->width() != w)  ||  (testDataFieldDbl->height() != h)){
		cout << "Error: " << testName << " with init state.\n";
		return false;
	}
	cout << ".";

	return true;
}



bool TestDataFieldDbl::testInitSize1(string testName){
	int width=0;
	int height=1;
	DataFieldDbl *testDataFieldDbl = NULL;
	try{
		testDataFieldDbl = new  DataFieldDbl(width,height);
		cout << "Error: " << testName << " 0,1 init.\n";
		return false;
	}catch(std::invalid_argument &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) 0,1 init:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) 0,1 init:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}

bool TestDataFieldDbl::testInitSize2(string testName){
	int width=1;
	int height=0;
	DataFieldDbl *testDataFieldDbl = NULL;
	try{
		testDataFieldDbl = new  DataFieldDbl(width,height);
		cout << "Error: " << testName << " 0,1 init.\n";
		return false;
	}catch(std::invalid_argument &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) 0,1 init:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) 0,1 init:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}

bool TestDataFieldDbl::testInitSize3(string testName){
	int width=0;
	int height=0;
	DataFieldDbl *testDataFieldDbl = NULL;
	try{
		testDataFieldDbl = new  DataFieldDbl(width,height);
		cout << "Error: " << testName << " 0,1 init.\n";
		return false;
	}catch(std::invalid_argument &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) 0,1 init:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) 0,1 init:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}

bool TestDataFieldDbl::testInitSize4(string testName){
	int width=-1;
	int height=1;
	DataFieldDbl *testDataFieldDbl = NULL;
	try{
		testDataFieldDbl = new  DataFieldDbl(width,height);
		cout << "Error: " << testName << " 0,1 init.\n";
		return false;
	}catch(std::invalid_argument &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) 0,1 init:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) 0,1 init:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}


bool TestDataFieldDbl::testInitSize5(string testName){
	int width=1;
	int height=-1;
	DataFieldDbl *testDataFieldDbl = NULL;
	try{
		testDataFieldDbl = new  DataFieldDbl(width,height);
		cout << "Error: " << testName << " 0,1 init.\n";
		return false;
	}catch(std::invalid_argument &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) 0,1 init:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) 0,1 init:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}

bool TestDataFieldDbl::testRangeWidth(string testName){
	int width=5;
	int height=3;
	DataFieldDbl *testDataFieldDbl = NULL;
	try{
		testDataFieldDbl = new  DataFieldDbl(width,height);

		if(testDataFieldDbl->width() != width){
			cout << "Error: " << testName << " wrong width:\n";
			if(testDataFieldDbl != NULL) delete testDataFieldDbl;
			return false;
		}

	}catch(...){
		cout << "Error: " << testName << " incorrect exception:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}




bool TestDataFieldDbl::testRangeHeight(string testName){
	int width=5;
	int height=3;
	DataFieldDbl *testDataFieldDbl = NULL;
	try{
		testDataFieldDbl = new  DataFieldDbl(width,height);

		if(testDataFieldDbl->height() != height){
			cout << "Error: " << testName << " wrong height:\n";
			if(testDataFieldDbl != NULL) delete testDataFieldDbl;
			return false;
		}

	}catch(...){
		cout << "Error: " << testName << " incorrect exception:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}

bool TestDataFieldDbl::testSetGet(string testName){
	int width=7;
	int height=3;
	DataFieldDbl *testDataFieldDbl = NULL;
	try{
		testDataFieldDbl = new  DataFieldDbl(width,height);
	}catch(...){
		cout << "Error: " << testName << " incorrect exception:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	try{

		for(int w=0; w < width; w++){
			for(int h=0; h < height; h++){
				testDataFieldDbl->get(w,h);
			}
		}

	}catch(...){
		cout << "Error: " << testName << " incorrect exception:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}


bool TestDataFieldDbl::testSetGet1(string testName){
	int width=7;
	int height=3;
	DataFieldDbl *testDataFieldDbl = NULL;

	testDataFieldDbl = new  DataFieldDbl(width,height);

	try{
		testDataFieldDbl->get(width,0);
		cout << "Error: " << testName << " no exception with wrong width:\n";
		return false;
	}catch(std::out_of_range &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	try{
		testDataFieldDbl->get(-1,0);
		cout << "Error: " << testName << " no exception with wrong width:\n";
		return false;
	}catch(std::out_of_range &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;

}

bool TestDataFieldDbl::testSetGet2(string testName){
	int width=7;
	int height=3;
	DataFieldDbl *testDataFieldDbl = NULL;

	testDataFieldDbl = new  DataFieldDbl(width,height);


	try{
		testDataFieldDbl->get(0,height);
		cout << "Error: " << testName << " no exception with wrong width:\n";
		return false;
	}catch(std::out_of_range &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}


	try{
		testDataFieldDbl->get(0,-1);
		cout << "Error: " << testName << " no exception with wrong width:\n";
		return false;
	}catch(std::out_of_range &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}


bool TestDataFieldDbl::testSetGet3(string testName){
	int width=7;
	int height=3;
	DataFieldDbl *testDataFieldDbl = NULL;

	testDataFieldDbl = new  DataFieldDbl(width,height);


	try{
		for(int w = 0; w < width; w++){
			for(int h=0; h < height; h++){
				testDataFieldDbl->set(w,h,12);
			}
		}
	}catch(...){
		cout << "Error: " << testName << " incorrect exception:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}


bool TestDataFieldDbl::testSetGet4(string testName){
	int width=7;
	int height=3;
	DataFieldDbl *testDataFieldDbl = NULL;

	testDataFieldDbl = new  DataFieldDbl(width,height);

	try{
		testDataFieldDbl->set(width,0,12);
		cout << "Error: " << testName << " no exception with wrong width:\n";
		return false;
	}catch(std::out_of_range &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	try{
		testDataFieldDbl->set(-1,0,13);
		cout << "Error: " << testName << " no exception with wrong width:\n";
		return false;
	}catch(std::out_of_range &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;

}

bool TestDataFieldDbl::testSetGet5(string testName){
	int width=7;
	int height=3;
	DataFieldDbl *testDataFieldDbl = NULL;

	testDataFieldDbl = new  DataFieldDbl(width,height);


	try{
		testDataFieldDbl->set(0,height,14);
		cout << "Error: " << testName << " no exception with wrong width:\n";
		return false;
	}catch(std::out_of_range &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}


	try{
		testDataFieldDbl->set(0,-1,15);
		cout << "Error: " << testName << " no exception with wrong width:\n";
		return false;
	}catch(std::out_of_range &e){
		;; // korrekt catch
	}catch(std::runtime_error &e){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << e.what() << endl;
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}catch(...){
		cout << "Error: " << testName << " incorrect catch(...) get with wrong width:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}


bool TestDataFieldDbl::testSetGet6(string testName){
	int width=7;
	int height=3;
	DataFieldDbl *testDataFieldDbl = NULL;

	testDataFieldDbl = new  DataFieldDbl(width,height);

	int counter = 0;
	try{
		for(int w = 0; w < width; w++){
			for(int h=0; h < height; h++){
				testDataFieldDbl->set(w,h,counter);
				counter++;
			}
		}
	}catch(...){
		cout << "Error: " << testName << " incorrect exception:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}


	counter = 0;
	try{
		for(int w = 0; w < width; w++){
			for(int h=0; h < height; h++){
				if(counter != testDataFieldDbl->get(w,h) ){
					cout << "Error: " << testName << " read wrong  value:\n";
					if(testDataFieldDbl != NULL) delete testDataFieldDbl;
					return false;
				}
				counter++;
			}
		}
	}catch(...){
		cout << "Error: " << testName << " incorrect exception:\n";
		cout << "unknown error\n";
		if(testDataFieldDbl != NULL) delete testDataFieldDbl;
		return false;
	}

	if(testDataFieldDbl != NULL) delete testDataFieldDbl;
	cout << ".";

	return true;
}



} // end namespace SemesterProgramming
