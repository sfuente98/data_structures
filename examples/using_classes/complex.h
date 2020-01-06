#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

#include <string>
#include <sstream>

class Complex {
private:
	float real, imaginary;

public:
	Complex();
	Complex(const Complex&);
	Complex(float);
	Complex(float, float);

	//float getReal() const;
	//float getImaginary() const;
	std::string toString() const;

	void operator=(const Complex&);
	void operator+=(const Complex&);

	friend Complex operator+(const Complex&, const Complex&);
	friend int operator< (const Complex &, const Complex &);
};

Complex::Complex() {
	real = imaginary = 0;
}

Complex::Complex(const Complex &a) {
	real = a.real; // this->real = a.real;
	imaginary = a.imaginary; // this->imaginary = a.imaginary;
}

Complex::Complex(float r) {
	real = r;
	imaginary = 0;
}

Complex::Complex(float r, float i) : real(r), imaginary(i) {
}

/*
float Complex::getReal() const {
	return real;
 }

float Complex::getImaginary() const {
	return imaginary;
}
*/

std::string Complex::toString() const {
	std::stringstream aux;

	aux << real << " + " << imaginary << "i";
	return aux.str();
}

void Complex::operator=(const Complex &right) {
	real = right.real;
	imaginary = right.imaginary;
}

void Complex::operator+=(const Complex &right) {
	real = real + right.real;
	imaginary = imaginary + right.imaginary;
}

Complex operator+ (const Complex &left, const Complex &right) {
	float r = left.real + right.real;
	float i = left.imaginary + right.imaginary;

	return Complex(r, i);
}

int operator< (const Complex &left, const Complex &right) {
	return left.real < right.real;
}

#endif
