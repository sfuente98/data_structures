/**
    File: intro.h
    Purpose: Show the differences in C and C ++.

    @author Pedro Perez
    @version 2.0 13/01/2019
*/
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

typedef unsigned long int uli;
typedef unsigned char uchar;

/**
	Calculate the factorial of a number.
	
	@param n an integer number.
	@return the factorial of n.
*/
unsigned long fact(int n) {
	unsigned long acum;

	if (n <= 0) {
		return 0;
	}

	acum = 1;
	for (int i = 1; i <= n; i++) {
		acum *= i;
	}
	return acum;
}

/**
	Determines if a number is a prime number or not.
	
	@param n an integer number.
	@return true if n is a prime number; otherwise retuns false.
*/
bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}

	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

/**
	Calculate the sum of all the elements of an array.
	
	@param arr an integer array.
	@param size the number of elements of the array.
	@return the sum of all elements.
*/
unsigned long sum(int arr[], int size) {
	unsigned long acum = 0;
	for (int i = 0; i < size; i++) {
		acum += arr[i];
	}
	return acum;
}

/**
	Inverts the position of the elements of an array.
	
	@param arr an integer array.
	@param size the number of elements of the array.
*/
void reverse(int arr[], int size) {
/*
	int aux;
	int i = 0;
	int j = size - 1;

	while (i < j) {
		aux = arr[i];
		arr[i] = arr[j];
		arr[j] = aux;
		i++;
		j--;
	}
	*/
}

#endif /* FUNCTIONS_H_ */
