/**
    File: vector.h
    Purpose: This file contains the implementation of the vector class

    @author Pedro Perez
    @version 2.0 6/01/2020
*/
#ifndef VECTOR_H_
#define VECTOR_H_

#include "../../includes/exception.h"
#include <string>
#include <sstream>

template <class T>
class vector {
private:
	unsigned int size;
	T	*data;

public:
	vector(unsigned int);
	vector(unsigned int, T&);
	vector(const vector<T>&);
	~vector();

	unsigned int length() const;
	unsigned int resize(unsigned int);
	unsigned int resize(unsigned int, T&);
	std::string to_string() const;

	T& operator[](unsigned int) const;
	void operator=(const vector<T>&);
};

/**
	Constructor. Receives the initial size of the vector.
	
	@param numberOfElements initial size of the vector
*/
template <class T>
vector<T>::vector(unsigned int numberOfElements) {
    if(numberOfElements == 0){
        throw RangeError();
    }
    size = numberOfElements;
    data = new T[size];
    if(data == 0){
        throw OutOfMemory();
    }
}

/**
	Constructor. Receives the initial size and the initiel values 
	for each of position of the vector.
	
	@param numberOfElements initial size of the vector
	@param initialValues initial value for each position in the vector.
*/
template <class T>
vector<T>::vector(unsigned int numberOfElements, T &initialValue) {
    if(numberOfElements == 0){
        throw RangeError();
    }
    size = numberOfElements;
    data = new T[size];
    if(data == 0){
        throw OutOfMemory();
    }
    for(unsigned int i = 0; i < size; i++){
        data[i] = initialValue;
    }
}

/**
	Copy constructor. It will create a copy of the source vector.
	
	@param source the vector of which it will create a copy.
*/
template <class T>
vector<T>::vector(const vector<T> &source) {
    size = source.size;
    data = new T[size];
    if(data == 0){
        throw OutOfMemory();
    }
    for(unsigned int i = 0; i < size; i++){
        data[i] = source.data[i];
    }
}

/**
	Destructor. Free the memory space used by the class.
*/
template <class T>
vector<T>::~vector() {
    delete [] data;
    data = 0;
    size = 0;
}

/**
	Return the size of the vector.
*/
template <class T>
unsigned int vector<T>::length() const {
	return size;
}

/**
	Resize the vector. If thew new size is less than the 
	original size, only copy the first element. Otherwise, 
	copy all the values.
	
	@param newSize the new size of the vector.
	@return the new vector size.
*/
template <class T>
unsigned int vector<T>::resize(unsigned int newSize) {
	if (newSize == 0){
        throw RangeError();
	}

    T *newData = new T[newSize];
    if(newData == 0){
        throw OutOfMemory();
    }

    if(newSize <= size){
        for(unsigned int i = 0; i < newSize; i++){
            newData[i] = data[i];
        }
    } else{
        for(unsigned int i = 0; i < size; i++){
            newData[i] = data[i];
        }
    }

	delete [] data;
	data = newData;
	size = newSize;

	return size;
}

/**
	Resize the vector. If thew new size is less than the 
	original size, only copy the first element. Otherwise, 
	copy all the values and the empty locations are initialized
	with initValue.
	
	@param newSize the new size of the vector.
	@param initValue the initial value of the new locations.
	@return the new vector size.
*/
template <class T>
unsigned int vector<T>::resize(unsigned int newSize, T &initValue) {
	if (newSize == 0){
        throw RangeError();
	}
    T *newData = new T[newSize];

    if(newData == 0){
        throw OutOfMemory();
    }

    if(newSize <= size){
        for(unsigned int i = 0; i < newSize; i++){
            newData[i] = data[i];
        }
    }else{
        unsigned int i;
        for( i = 0; i < size; i++){
            newData[i] = data[i];
        }
        for( ; i < newSize; i++){
			newData[i] = initValue;
        }
    }
	delete [] data;
	data = newData;
	size = newSize;

	return size;
}

/**
	Return the string representation of the vector.
	
	@return a string representation.
*/
template <class T>
std::string vector<T>::to_string() const {
	std::stringstream aux;

	aux << "[" << data[0];
	for (unsigned int i = 1; i < size; i++) {
		aux << ", " << data[i];
	}
	aux << "]";
	return aux.str();
}

/**
	Overload the operator [] to operate with the vector class.
	
	@param index a valid position of the vector.
	@return the value, by reference, which is in the position 
			indicated by index.
*/
template <class T>
T& vector<T>::operator[] (unsigned int index) const {
    if(index >= size){
        throw IndexOutOfBounds();
    }
	return data[index];
}

/**
	Overload the assignment operator. Make an identical copy 
	of the source vector.
	
	@param source the vector to be copied
*/
template <class T>
void vector<T>::operator=(const vector<T> &right) {
    if(size != right.size){
        resize(right.size);
    }
    for(unsigned int i =0; i < right.size; i++){
        data[i] = right.data[i];
    }
}

#endif /* VECTOR_H_ */
