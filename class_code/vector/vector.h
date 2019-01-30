/*
 * vector.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include "../includes/exception.h"
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
    for(int i =0; i<size; i++){
        data[i] = initialValue;
    }
}

template <class T>
vector<T>::vector(const vector<T> &source) {
    size = source.size;
    data = new T[size];
    if(data == 0){
        throw OutOfMemory();
    }
    for(unsigned i =0; i<size; i++){
        data[i] = source.data[i];
    }
}

template <class T>
vector<T>::~vector() {
    delete [] data;
    data = 0;
    size = 0;
}

template <class T>
unsigned int vector<T>::length() const {
	return size;
}

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
        for( ;i < newSize; i++){
                newData[i] = initValue;
        }
    }
	delete [] data;
	data = newData;
	size = newSize;

	return size;
}

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

template <class T>
T& vector<T>::operator[] (unsigned int index) const {
    if(index >= size){
        throw IndexOutOfBounds();
    }
	return data[index];
}

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
