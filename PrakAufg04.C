/*
 * PrakAufg04.C
 *
 *  Created on: 26.05.2018
 *      Author: aml
 */

#include "PrakAufg04.H"

#include <string>
#include <iostream>
#include <random>

using namespace std;

int Matrix::fieldIdx(int m, int n) const {
	return ((n_ * m) + n);
}


Matrix::Matrix() {
		dataField_ = nullptr;
		m_ = 0;
		n_ = 0;
		generator_ = new default_random_engine(time(NULL));
		internalGen_ = true;
}

Matrix::Matrix(default_random_engine *g){
	dataField_ = nullptr;
	m_ = 0;
	n_ = 0;
	generator_ = g;
	internalGen_ = false;
}


Matrix::Matrix(const Matrix &m) : Matrix() {
	this->m_ = m.getMdim();
	this->n_ = m.getNdim();
	if ((this->m_ * this->n_) > 0) {
		this->dataField_ = new double[m_ * n_];
		for (int i = 0; i < this->m_ * this->n_; i++) {
			this->dataField_[i] = m.dataField_[i];
			this->generator_ = new default_random_engine(time(NULL));
			this->internalGen_ = true;
		}
	} else {
		this->dataField_ = nullptr;
		this->n_ = 0;
		this->m_ = 0;
		generator_ = new default_random_engine(time(NULL));
		internalGen_ = true;
	}
}

Matrix::Matrix(int m, int n) : Matrix(){
	this->init(m, n);
}

Matrix::~Matrix() {
	if (dataField_ != nullptr) {
		delete [] dataField_;
		dataField_ = nullptr;
	}
	if(internalGen_ && (generator_ != nullptr)){
		delete generator_;
	}

}

void Matrix::init(int m, int n) {
	if ((m < 1) || (n < 1)) {
		throw string("init: index out of range");
	}

	try {
		if (dataField_ != nullptr) {
			delete dataField_;
			dataField_ = nullptr;
		}
		dataField_ = new double[m * n];
		m_ = m;
		n_ = n;
	} catch (...) {
		if (dataField_ != nullptr) {
			delete [] dataField_;
			m_ = 0;
			n_ = 0;
			dataField_ = nullptr;
		} else {
			dataField_ = nullptr;
			m_ = 0;
			n_ = 0;
		}
		return;
	}

	for (int i = 0; i < m_ * n_; i++) {
		dataField_[i] = 0;
	}
}

void Matrix::set(int m, int n, double value) {
	if (dataField_ == nullptr)
		throw string("Matrix not defined");
	if ((m < 0) || (m >= m_))
		throw string("Out of range");
	if ((n < 0) || (n >= n_))
		throw string("Out of range");
	dataField_[this->fieldIdx(m, n)] = value;
}

double Matrix::get(int m, int n) const {
	if (dataField_ == nullptr)
		throw string("Matrix not defined");
	if ((m < 0) || (m >= m_))
		throw string("Out of range");
	if ((n < 0) || (n >= n_))
		throw string("Out of range");
	return (dataField_[this->fieldIdx(m, n)]);
}

int Matrix::getMdim() const {
	return m_;
}
;
int Matrix::getNdim() const {
	return n_;
}
;

void Matrix::out() {
	if (dataField_ == nullptr)
		throw string("Matrix not defined");
	for (int m = 0; m < m_; m++) {
		for (int n = 0; n < n_; n++) {
			cout << this->get(m, n) << "\t";
		}
		cout << endl;
	}
	return;
}

void Matrix::transfer(){
	for(int i=0; i < n_*m_; i++){
		dataField_[i] = fct(dataField_[i]);
	}
}

double Matrix::fct(double v){
	return v;
}

void   Matrix::initRand(double stdAbw){
	normal_distribution<double> distribution(0.0,2.0);
	for(int i=0; i < n_*m_; i++){
		dataField_[i] = distribution(*generator_);
	}

}

Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
	if (!((lhs.getMdim() == rhs.getMdim()) && (lhs.getNdim() == rhs.getNdim()))) {
		throw string("wrong dimension");
	}

	Matrix x(lhs);

	for (int n = 0; n < lhs.getNdim(); n++) {
		for (int m = 0; m < lhs.getMdim(); m++) {
			x.set(m, n, lhs.get(m, n) + rhs.get(m, n));
		}
	}
	return x;
}


Matrix operator*(const Matrix &lhs, double c){
	Matrix x(lhs);
	for (int n = 0; n < lhs.getNdim(); n++) {
		for (int m = 0; m < lhs.getMdim(); m++) {
			x.set(m, n, lhs.get(m, n)*c);
		}
	}
	return x;
}

Matrix operator*(double c, const Matrix &rhs){
	return (rhs*c);
}



Matrix& Matrix::operator=(const Matrix &rhs) {
	if (this == &rhs) {
		return *this;
	}
	try {

		this->m_ = rhs.getMdim();
		this->n_ = rhs.getNdim();
		if (m_ * n_ < 1) {
			throw string("rhs has wrong dimension.");
		} else {
			if (dataField_ != NULL) {
				delete dataField_;
			}
			dataField_ = new double[this->m_ * this->n_];
			for(int i=0; i<this->m_ * this->n_; i++){
				dataField_[i] = rhs.dataField_[i];
			}
		}
	} catch (...) {
		dataField_ = NULL;
		this->m_ = 0;
		this->n_ = 0;
	}

	return *this;
}



void MatrixTest::run() {
	cout << "unit tests:" << endl;
	cout << test01() << endl;
	cout << test02() << endl;
	cout << test03() << endl;
	cout << test04() << endl;
	cout << test05() << endl;
	cout << test06() << endl;
	cout << test07() << endl;
	cout << test08() << endl;
	cout << test09() << endl;
	cout << test10() << endl;
	cout << test11() << endl;
	cout << test12() << endl;
	cout << test13() << endl;
	cout << test14() << endl;
	cout << test15() << endl;
	cout << test16() << endl;
	cout << test17() << endl;
	cout << test18() << endl;
	cout << test19() << endl;
	cout << test20() << endl;
	cout << test21() << endl;
}

bool MatrixTest::test01() {
	cout << "test01: ";
	try {
		Matrix m(0, 0);
	} catch (...) {
		return true;
	}
	return false;
}

bool MatrixTest::test02() {
	cout << "test02: ";
	try {
		Matrix m(0, 2);
	} catch (...) {
		return true;
	}
	return false;
}

bool MatrixTest::test03() {
	cout << "test03: ";
	try {
		Matrix m(2, 0);
	} catch (...) {
		return true;
	}
	return false;
}

bool MatrixTest::test04() {
	cout << "test04: ";
	try {
		Matrix m(2, -3);
	} catch (...) {
		return true;
	}
	return false;
}

bool MatrixTest::test05() {
	cout << "test05: ";
	try {
		Matrix m(-3, 2);
	} catch (...) {
		return true;
	}
	return false;
}

bool MatrixTest::test06() {
	cout << "test06: ";
	try {
		Matrix m(3, 1);
	} catch (...) {
		return false;
	}
	return true;
}

bool MatrixTest::test07() {
	cout << "test07: ";
	try {
		Matrix m(1, 1);
		m.init(0, 0);
	} catch (...) {
		return true;
	}
	return false;
}

bool MatrixTest::test08() {
	cout << "test08: ";
	try {
		Matrix m(1, 1);
		m.init(0, 2);
	} catch (...) {
		return true;
	}
	return false;
}

bool MatrixTest::test09() {
	cout << "test09: ";
	try {
		Matrix m(1, 1);
		m.init(2, 0);
	} catch (...) {
		return true;
	}
	return false;
}

bool MatrixTest::test10() {
	cout << "test10: ";
	try {
		Matrix m(1, 1);
		m.init(2, -3);
	} catch (...) {
		return true;
	}
	return false;
}

bool MatrixTest::test11() {
	cout << "test11: ";
	try {
		Matrix m(1, 1);
		m.init(-3, 2);
	} catch (...) {
		return true;
	}
	return false;
}

bool MatrixTest::test12() {
	cout << "test12: ";
	try {
		Matrix m(1, 1);
		m.init(3, 1);
	} catch (...) {
		return false;
	}
	return true;
}

bool MatrixTest::test13() {
	cout << "test13: ";
	try {
		int n = 12;
		int m = 27;
		Matrix x(1, 1);
		x.init(m, n);
		if ((x.getMdim() != m) || (x.getNdim() != n)) {
			return false;
		}
	} catch (...) {
		return false;
	}
	return true;
}

bool MatrixTest::test14() {
	cout << "test14: ";
	try {
		int n;
		int m;
		Matrix *x;

		for (int c = 0; c < 1000; c++) {
			n = (rand() % 55) + 1;
			m = (rand() % 55) + 1;
			x = new Matrix(n, m);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (x->get(i, j) != 0.0)
						return false;
				}
			}
			delete x;
		}
	} catch (...) {
		return false;
	}
	return true;
}


bool MatrixTest::test15() {
	cout << "test15: ";
	try {
		int n;
		int m;
		Matrix x(1,1);

		for (int c = 0; c < 1000; c++) {
			n = (rand() % 55) + 1;
			m = (rand() % 55) + 1;
			x.init(n, m);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (x.get(i, j) != 0.0)
						return false;
				}
			}
		}
	} catch (...) {
		return false;
	}
	return true;
}


bool MatrixTest::test16() {
	cout << "test16: ";
	try {
		int n;
		int m;

		Matrix y(1,1);
		Matrix x(1,1);

		for (int c = 0; c < 1000; c++) {
			n = (rand() % 55) + 1;
			m = (rand() % 55) + 1;
			x.init(m,n);
			y = x;
			if(y.getMdim() != m) return false;
			if(y.getNdim() != n) return false;
		}
	} catch (...) {
		return false;
	}
	return true;
}



bool MatrixTest::test17() {
	cout << "test17: ";
	try {
		int n;
		int m;

		Matrix x(1,1);

		for (int c = 0; c < 1000; c++) {
			n = (rand() % 55) + 1;
			m = (rand() % 55) + 1;
			x.init(m,n);
			x = x;
			if(x.getMdim() != m) return false;
			if(x.getNdim() != n) return false;
		}
	} catch (...) {
		return false;
	}
	return true;
}


bool MatrixTest::test18() {
	cout << "test18: ";
	try {
		int n;
		int m;

		default_random_engine *generator = new default_random_engine(time(NULL));

		Matrix x(generator);
		Matrix y(generator);
		Matrix z;


		for (int c = 0; c < 1000; c++) {
			n = (rand() % 55) + 1;
			m = (rand() % 55) + 1;

			x.init(m,n);
			y.init(m,n);
			x.initRand(1.0);
			y.initRand(2.0);

			z = x + y;

			for(int i=0; i < x.getMdim(); i++){
				for(int j=0; j < x.getNdim(); j++){
					if(z.get(i,j) != (x.get(i,j) + y.get(i,j)) ) return false;
				}
			}
		}
	} catch (...) {
		return false;
	}
	return true;
}


bool MatrixTest::test19() {
	cout << "test19: ";
	try {
		int n;
		int m;

		default_random_engine *generator = new default_random_engine(time(NULL));

		Matrix x(generator);
		Matrix y(generator);

		for (int c = 0; c < 1000; c++) {
			n = (rand() % 55) + 1;
			m = (rand() % 55) + 1;

			x.init(m,n);
			y.init(m,n);
			x.initRand(1.0);
			y.initRand(1.0);

			for(int i=0; i < x.getMdim(); i++){
				for(int j=0; j < x.getNdim(); j++){
					if(x.get(i,j) == y.get(i,j) ) return false;
				}
			}
		}
	} catch (...) {
		return false;
	}
	return true;
}



bool MatrixTest::test20() {
	cout << "test20: ";
	try {
		int n;
		int m;
		int factor  = 10;

		default_random_engine *generator = new default_random_engine(time(NULL));

		Matrix x(generator);
		Matrix z;

		for (int c = 0; c < 1000; c++) {
			n = (rand() % 55) + 1;
			m = (rand() % 55) + 1;

			x.init(m,n);
			x.initRand(10.0);
			z = x*factor;

			for(int i=0; i < x.getMdim(); i++){
				for(int j=0; j < x.getNdim(); j++){
					if(z.get(i,j) != x.get(i,j)*factor ) return false;
				}
			}
		}
	} catch (...) {
		return false;
	}
	return true;
}


bool MatrixTest::test21() {
	cout << "test21: ";
	try {
		int n;
		int m;
		int factor  = 10;

		default_random_engine *generator = new default_random_engine(time(NULL));

		Matrix x(generator);
		Matrix z;

		for (int c = 0; c < 1000; c++) {
			n = (rand() % 55) + 1;
			m = (rand() % 55) + 1;

			x.init(m,n);
			x.initRand(10.0);
			z = factor*x;

			for(int i=0; i < x.getMdim(); i++){
				for(int j=0; j < x.getNdim(); j++){
					if(z.get(i,j) != x.get(i,j)*factor ) return false;
				}
			}
		}
	} catch (...) {
		return false;
	}
	return true;
}
