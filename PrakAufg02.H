/*
 * PrakAufg02.H
 *
 *  Created on: 03.05.2018
 *      Author: aml
 */

#ifndef PRAKAUFG02_H_
#define PRAKAUFG02_H_

#include <stdexcept>

using namespace std;


namespace SemesterProgramming{

/**
 *
 * \file PrakAufg02.H
 *
 * \brief Contains the definition of class DataField .
 *
 */

/**
 *
 *  \class IDataFieldDbl
 *  \brief     Class IDataFieldDbl base class implementing core functionality
 *  of the 2-dimensional data field - a container of double values.
 *
 *
 *
 */
class IDataFieldDbl {
public:

	/**
	 * \brief Gives the currently defined width-dimension.
	 *
	 * \return int width-dimension size of the 2-dimensional data field
	 *
	 */
	virtual int width() = 0;

	/**
	 * \brief Gives the currently defined height-dimension.
	 *
	 * \return int width-dimension size of the 2-dimensional data field
	 *
	 */
	virtual int height() = 0;


	/**
	 *
	 * \brief Assigns the data item of the 2-dimensional data field for the given index
	 *
	 * @param w  width-dimension index of the 2-dimensional data field
	 * @param h  height-dimension index of the 2-dimensional data field
	 * @param value  double data item contains the data to be assigned
	 * \throws std::out_of_range if one index parameter is out of range of the given 2-dimensional data field.
	 *
	 */
	virtual void set(int w, int h, double value) throw (out_of_range) = 0;

	/**
	 *
	 * \brief Returns the value of the 2-dimensional data field for the given index
	 *
	 * @param w  width-dimension index of the 2-dimensional data field
	 * @param h  height-dimension index of the 2-dimensional data field
	 *
	 * \return double value stored at the given coordinates
	 *
	 * \throws std::out_of_range if one dimension parameters is smaller 1.
	 *
	 * \throws std::out_of_range if one index parameter is out of range of the given 2-dimensional data field
	 *
	 */
	virtual double get(int w, int h) throw (out_of_range) = 0;

};

/**
 *
 *  \class DataFieldDbl
 *  \brief   Derived from class IDataFieldDbl implementing the 2-dimensional
 *  data field for double-values.
 *
 */
class DataFieldDbl: public IDataFieldDbl {
public:
	/**
	 *
	 * \brief Constructor of the 2-dimensional data field
	 *
	 * @param wDim  width-dimension of the 2-dimensional data field
	 * @param hDim  height-dimension of the 2-dimensional data field
	 * \throws std::invalid_argument or std::runtime_error if one dimension parameters is
	 *         smaller 1 or memory allocation fails.
	 *
	 */
	DataFieldDbl(int wDim = 1, int hDim = 1);

	/**
	 *
	 * Destructor
	 *
	 *
	 */
	~DataFieldDbl();



	int width();

	int height();

	void set(int w, int h, double value) throw (out_of_range);

	double get(int w, int h) throw (out_of_range);

protected:

	/**
	 *
	 * \brief Constructor of the 2-dimensional data field
	 *
	 * @param wDim  width-dimension of the 2-dimensional data field
	 * @param hDim  height-dimension of the 2-dimensional data field
	 * \throws std::invalid_argument or std::runtime_error if one dimension parameters is
	 *         smaller 1 or memory allocation fails.
	 *
	 */
	void init(int wDim, int hDim) throw (invalid_argument, runtime_error);


	/**
	 *
	 * \brief Assigns the data item of the 1-dimensional array for the given index
	 *
	 * @param idx  index of the array storing the data items
	 * @param value  double  contains the data to be assigned
	 *
	 */
	void setValue(int idx, double const value);

	/**
	 *
	 * \brief Returns the value of the 1-dimensional array  for the given global index
	 *
	 * @param idx  index of the array storing the data items
	 * \return double value of the data at the given index
	 *
	 */
	double getValue(int idx);

	/**
	 *
	 * Returns the index of the 1-dimensional array derived from the (w,h)-parameter of the
	 * 2-dimensional data field.
	 *
	 * @return int global index
	 */
	int glbIndex(int w, int h) throw (std::runtime_error);

	/**
	 *
	 * Throws and exception if  the given (w,h)-parameter is out of range of the currently
	 * initialized data field.
	 *
	 * @return int global index
	 */
	void checkRange(int w, int h) throw (std::out_of_range);


	/**
	 *
	 * Reference to the allocated memory storing the
	 * the values of the 2-d data field
	 *
	 */
	double *ptrDataField_;

	/**
	 *
	 * vertical dimension of the 2-d data field
	 *
	 */
	int wDim_;


	/**
	 *
	 * horizontal dimension of the 2-d data field
	 *
	 */
	int hDim_;
};

/**
 *
 * \brief class for testing instance of IDataField
 *
 */
class TestDataFieldDbl {
public:

	/**
	 *
	 * \brief Constructor
	 *
	 */
	TestDataFieldDbl();

	/**
	 * \brief Runs all tests.
	 *
	 * \return true if all test successfully passed, otherwise false
	 *
	 */
	bool runTest();

protected:

	/**
	 *
	 * Unit test
	 *
	 */
	bool testInitSize1(string);

	/**
	 *
	 * Unit test
	 *
	 */
	bool testInitSize2(string);


	/**
	 *
	 * Unit test
	 *
	 */
	bool testInitSize3(string);


	/**
	 *
	 * Unit test
	 *
	 */
	bool testInitSize4(string);


	/**
	 *
	 * Unit test
	 *
	 */
	bool testInitSize5(string);

	/**
	 * Unit test
	 *
	 */
	bool testConstr(string);


	/**
	 * Unit test
	 *
	 */
	bool testRangeWidth(string);

	/**
	 * Unit test
	 *
	 */
	bool testRangeHeight(string);


	/**
	 * Unit test
	 *
	 */
	bool testSetGet(string);

	/**
	 * Unit test
	 *
	 */
	bool testSetGet1(string);


	/**
	 * Unit test
	 *
	 */
	bool testSetGet2(string);

	/**
	 * Unit test
	 *
	 */
	bool testSetGet3(string);

	/**
	 * Unit test
	 *
	 */
	bool testSetGet4(string);

	/**
	 * Unit test
	 *
	 */
	bool testSetGet5(string);

	/**
	 * Unit test
	 *
	 */
	bool testSetGet6(string);
};

} // end namespace SemesterProgramming

#endif /* PRAKAUFG02_H_ */
