#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <sstream>
#include <list>
#include "../includes/exception.h"

typedef unsigned int uint;

template <class T>
class stack {
public:
	virtual void push(T) = 0;
	virtual T top() const = 0;
	virtual void pop() = 0;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
	virtual std::string to_string() const = 0;
};

template <class T>
class stack_vector : public stack<T> {
private:
	uint next;
	uint size;
	T 			 *data;

public:
	stack_vector(uint);
	~stack_vector();
	void push(T);
	T top() const;
	void pop();
	bool empty() const;
	void clear();
	std::string to_string() const;
};

template <class T>
stack_vector<T>::stack_vector(uint sze) {
    size = sze;
    data = new T[size];
    if (data == 0) {
        throw OutOfMemory();
    }
    next = 0;
}

template <class T>
stack_vector<T>::~stack_vector() {
    delete [] data;
    data = 0;
    next = 0;
}

template <class T>
void stack_vector<T>::push(T val) {
    if (next >= size) {
        throw Overflow();
    }
    data[next++] = val;
}

template <class T>
T stack_vector<T>::top() const {
	if (empty()) {
        throw NoSuchElement();
	}
    return data[next-1];
}

template <class T>
void stack_vector<T>::pop() {
	if (empty()) {
        throw NoSuchElement();
	}
    next --;
}

template <class T>
bool stack_vector<T>::empty() const {
    return (next == 0);
}

template <class T>
void stack_vector<T>::clear() {
    next = 0;
}

template <class T>
std::string stack_vector<T>::to_string() const {
	std::stringstream aux;

	aux << "[";
	if (next > 0) {
		aux << data[0];
		for (int i = 1; i < next; i++) {
			aux << ", " << data[i];
		}
	}
	aux << "]";
	return aux.str();
}

template <class T>
class stack_list : public stack<T> {
private:
	std::list<T> data;

public:
	void push(T);
	T top() const;
	void pop();
	bool empty() const;
	void clear();
	std::string to_string() const;
};

template <class T>
void stack_list<T>::push(T val) {
    data.push_front(val);
}

template <class T>
T stack_list<T>::top() const {
	if (data.empty()) {
        throw NoSuchElement();
	}
    return data.front();
}

template <class T>
void stack_list<T>::pop() {
    if (data.empty()) {
        throw NoSuchElement();
	}
    data.pop_front();
}

template <class T>
bool stack_list<T>::empty() const {
	return data.empty();
}

template <class T>
void stack_list<T>::clear() {
    data.clear();
}

template <class T>
std::string stack_list<T>::to_string() const {
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
#endif /* STACK_H_ */
