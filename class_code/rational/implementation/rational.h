/**
    File: rational.h
    Purpose: This file contains the implementation of the rational class

    @author Pedro Perez
    @version 2.0 13/01/2019
*/

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "../../includes/exception.h"
#include <string>
#include <sstream>

class rational {
private:
	int numerator;
	int denominator;

	int gcd(int, int) const;
	void normalize();

public:
	rational();
	rational(int);
	rational(int, int);
	rational(const rational&);

	int get_numerator() const;
	int get_denominator() const;
	std::string to_string() const;

	void operator=  (const rational&);
	void operator+= (const rational&);

	operator double () const;
};

/**
	Constructor by default of the class. 
*/
rational::rational() 
: numerator(0), denominator(1) {}

/**
	Constructor. Receives as a value the initial value of the 
	instance variable numerator
	
	@param num initial value of numerator
*/
rational::rational(int num) 
: numerator(num), denominator(1) {}

/**
	Constructor. Initializes both instance variables.
	
	@param num initial value of numerator.
	@param dem initial value of denominator.
*/
rational::rational(int num, int dem) 
: numerator(num), denominator(dem) {
	normalize();
}

/**
	Returns the current value the instance variable numerator.
	
	@return current value of numerator.
*/
int rational::get_numerator() const {
	return numerator;
}

/**
	Returns the current value the instance variable denominator.
	
	@return current value of denominator.
*/
int rational::get_denominator() const {
	return denominator;
}

/**
	Returns a string representation of the object.
	
	@return an string representation of the object.
*/
std::string rational::to_string() const {
	std::stringstream aux;

	aux << numerator << "/" << denominator;
	return aux.str();
}

/**
	Assigns new contents to the container, replacing its current contents.
*/
void rational::operator= (const rational &right) {
	numerator   = right.numerator;
	denominator = right.denominator;
}

/**
	Add content to the container, replacing its current contents.
*/
void rational::operator+= (const rational &right) {
	numerator    = (numerator * right.denominator) + (denominator * right.numerator);
	denominator *= right.denominator;
	normalize();
}

/**
	Returns a double representation of the object.
	
	@return double representation of the objetc.
*/
rational::operator double () const {
	return numerator / (double) denominator;
}

/**
	Calculate the greatest common divisor of two integer values.
	
	@param a integer value.
	@param b integer value.
	@return  the greatest common divisor.
*/
int rational::gcd(int a, int b) const {
	int aux;

	while (b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

/**
	Normalize rational by: move sign to numerator, make sure numerator 
	and denominator have no common divisors.
*/
void rational::normalize() {
	int sign = 1;
	if (numerator < 0) {
		sign = -1;
		numerator = -numerator;
	}
	if (denominator < 0) {
		sign = -sign;
		denominator = -denominator;
	}
	if (denominator == 0) {
		throw RangeError();
	}

	int d = gcd(numerator, denominator);

	numerator   = sign * (numerator / d);
	denominator = denominator / d;
}

/**
	Returns addition of two rational numbers.
*/
rational operator+ (const rational &left, const rational &right) {
	int num, dem;

	num = (left.get_numerator() * right.get_denominator()) + (left.get_denominator() * right.get_numerator());
	dem = left.get_denominator() * right.get_denominator();

	return rational(num, dem);
}

/**
	Returns the difference of two rational numbers.
*/
rational operator- (const rational &left, const rational &right) {
	int num, dem;

	num = (left.get_numerator() * right.get_denominator()) - (left.get_denominator() * right.get_numerator());
	dem = left.get_denominator() * right.get_denominator();

	return rational(num, dem);
}

/**
	Returns negation of a rational number.
*/
rational operator- (const rational &right) {
	return rational(-right.get_numerator(), right.get_denominator());
}

/**
	Returns true if left is equal than right
*/
bool operator== (const rational &left, const rational &right) {
	return (left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator());
}

/**
	Returns true if left is less than right
*/
bool operator<  (const rational &left, const rational &right) {
	return (left.get_numerator() * right.get_denominator()) < (left.get_denominator() * right.get_numerator());
}

#endif /* RATIONAL_H_ */
