/*
 * V03.H
 *
 *  Created on: 08.05.2018
 *      Author: aml
 */

#ifndef V03_H_
#define V03_H_

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Aufruf der Demos
 *
 */
void demoV03_komplexeZahlen();

namespace V03{

/**
 *
 * Class representing complex numbers
 *
 */
class complexNmb{


	/**
	 *
	 * \brief represents the real-part of the complex number (float-value)
	 *
	 */
	float re_ = 0;

	/**
	 *
	 * \brief represents the imaginary-part of the complex number (float-value)
	 *
	 */
	float im_ = 0;


public:


	/**
	 *
	 * \brief Returns the real-part of the complex number
	 *
	 * \return float value of the real-part
	 *
	 */
	float re();

	/**
	 *
	 * \brief Returns the imaginary-part of the complex number
	 *
	 * \return float value of the imaginary-part
	 *
	 */
	float im();

	/**
	 *
	 * \brief Sets the real-part of the complex number
	 *
	 * \@param float re new value of the real-part
	 *
	 */
	void re(float re);

	/**
	 *
	 * \brief Sets the  imaginary-part of the complex number
	 *
	 * \@param float re new value of the imaginary-part
	 *
	 */
	void im(float im);

	/**
	 *
	 * \brief Output of the complex number on screen
	 *
	 */
	void out();


	/**
	 *
	 * \brief Adding of the given complex number
	 *
	 * \@param complexNmb a to be added.
	 *
	 */
	void add(complexNmb b);

	/**
	 *
	 * \brief Suubstraction of the given complex number
	 *
	 * \@param complexNmb a to be substracted.
	 *
	 */
	void sub(complexNmb b);

	/**
	 *
	 * \brief Multiplying of the given complex number
	 *
	 * \@param complexNmb a to be multiplied.
	 *
	 */
	void mul(complexNmb b);

	/**
	 *
	 * \brief Division by the given complex number
	 *
	 * \@param complexNmb is the value of the divisor.
	 *
	 */
	void div(complexNmb b);

	/**
	 *
	 * \brief Generates the complex conjugation
	 *
	 */
	void con();
};

} // end namespace V03;

#endif /* V03_H_ */
