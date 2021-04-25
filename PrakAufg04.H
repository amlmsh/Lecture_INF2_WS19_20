/*
 * PrakAufg04.H
 *
 *  Created on: 26.05.2018
 *      Author: aml
 */

#ifndef PRAKAUFG04_H_
#define PRAKAUFG04_H_

#include <cstddef>
#include <random>
#include <chrono>

using namespace std;

class IMatrix{
public:
	virtual void   init(int m, int n)              = 0;
	virtual void   set(int m, int n, double value) = 0;
	virtual double get(int m, int n) const         = 0;
	virtual void   out()                           = 0;
	virtual int    getMdim()  const                = 0;
	virtual int    getNdim()  const                = 0;
	virtual void   initRand(double stdAbw)         = 0;
	virtual void   transfer()                      = 0;
};


class Matrix : public IMatrix{

	int m_, n_;
	double *dataField_ = nullptr;
	int fieldIdx(int m, int n) const;


	default_random_engine *generator_;
	bool internalGen_;

public:
	Matrix();
	Matrix(default_random_engine *g);
	Matrix(int m, int n);
	~Matrix();

	Matrix(const Matrix &m);

	void init(int m, int n);

	void   out();
	void   set(int m, int n, double value);
	double get(int m, int n) const;

	friend Matrix operator+(const Matrix &lhs, const Matrix &rhs);

	friend Matrix operator*(const Matrix &lhs, double c);
	friend Matrix operator*(double c, const Matrix &rhs);

	void transfer();


	Matrix& operator=(const Matrix &rhs);

	int    getMdim() const;
	int    getNdim() const;

	void   initRand(double stdAbw);

protected:
	virtual double fct(double v);

};

class MatrixTest{
public:
	void run();

private:
	bool test01();
	bool test02();
	bool test03();
	bool test04();
	bool test05();
	bool test06();
	bool test07();
	bool test08();
	bool test09();
	bool test10();
	bool test11();
	bool test12();
	bool test13();
	bool test14();
	bool test15();
	bool test16();
	bool test17();
	bool test18();
	bool test19();
	bool test20();
	bool test21();
};



#endif /* PRAKAUFG04_H_ */
