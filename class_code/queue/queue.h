/*
 * queue.h
 *
 *  Created on: 09/10/2015
 *      Author: clase
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "../includes/exception.h"
#include <list>
#include <string>
#include <sstream>
#include <iostream>

typedef unsigned int uint;

template <class T>
class queue {
public:
	virtual void enqueue(T) = 0;
	virtual void dequeue() = 0 ;
	virtual T front() const = 0 ;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
	virtual std::string to_string() const = 0;
};

template <class T>
class queue_vector : public queue<T> {
private:
	T *data;
	uint head, tail, size, counter;

public:
	queue_vector(uint);
	~queue_vector();
	void enqueue(T);
	void dequeue();
	T front() const;
	bool empty() const;
	bool full() const;
	void clear();
	std::string to_string() const;
};

template <class T>
queue_vector<T>::queue_vector(uint sze) {
    size = sze;
    data = new T[size];
    if (data == 0) {
        throw OutOfMemory();
    }
    head = 0;
    tail = 0;
    counter = 0;
}

template <class T>
queue_vector<T>::~queue_vector() {
    delete [] data;
    data = 0;
    head = 0;
    tail = 0;
    size = 0;
    counter = 0;
}

template <class T>
bool queue_vector<T>::empty() const {
    return (counter == 0);
}

template <class T>
bool queue_vector<T>::full() const {
    return (counter == size);
}

template <class T>
void queue_vector<T>::enqueue(T val) {
    if (full()) {
       throw Overflow();
    }
    data[tail] = val;
    tail = (tail + 1) % size;
    counter ++;
}

template <class T>
T queue_vector<T>::front() const {
    if (empty()) {
    	throw NoSuchElement();
    }
    
	return data[head];

}

template <class T>
void queue_vector<T>::dequeue() {
    if (empty()) {
        throw NoSuchElement();
    }
    head = (head + 1 ) % size;
    counter --;
}

template <class T>
void queue_vector<T>::clear() {
    tail = 0;
    head = 0;
    counter = 0;
}

template <class T>
std::string queue_vector<T>::to_string() const {
	std::stringstream aux;
	int i;

	aux << "[";
	if (!empty()) {
		i = head;
		aux << data[i];
		i = (i + 1) % size;
		while (i != tail) {
			aux << ", " << data[i];
			i = (i + 1) % size;
		}
	}
	aux << "]";
	return aux.str();
}

template <class T>
class queue_list : public queue<T> {
private:
	std::list<T> data;

public:
	void enqueue(T);
	void dequeue();
	T front() const;
	bool empty() const;
	void clear();
	std::string to_string() const;
};

template <class T>
void queue_list<T>::enqueue(T val) {
    data.push_back(val);
}

template <class T>
T queue_list<T>::front() const {
	if (empty()) {
		throw NoSuchElement();
	}
	
    return data.front();
}

template <class T>
void queue_list<T>::dequeue() {
	if (empty()) {
		throw NoSuchElement();
	}

    data.pop_front();
}

template <class T>
bool queue_list<T>::empty() const {
    return (data.empty());
}

template <class T>
void queue_list<T>::clear() {
    data.clear();
}

template <class T>
std::string queue_list<T>::to_string() const {
	std::stringstream aux;
	typename std::list<T>::const_iterator itr = data.begin();

	aux << "[";
	if (!data.empty()) {
		aux << (*itr);
		itr++;
		while (itr != data.end()) {
			aux << ", " << (*itr);
			itr++;
		}
	}
	aux << "]";
	return aux.str();
}

#endif /* QUEUE_H_ */
