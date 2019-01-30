/*
 * dlist.h
 *
 *  Created on: 10/08/2015
 *      Author: pperezm
 */

#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>
#include "../includes/exception.h"

template <class T> class dlist;

/* Declaration of the dlink class */
template <class T>
class dlink {
private:
	dlink(T);
	dlink(T, dlink<T>*, dlink<T>*);

	T	    value;
	dlink<T> *previous;
	dlink<T> *next;

	friend class dlist<T>;
};

/* Declaration of the dlist class */
template <class T>
class dlist {
private:
	dlink<T> *head;
	dlink<T> *tail;
	int 	 size;
	
	void copy(const dlist &);
	
public:
	dlist();
	dlist(const dlist<T>&);
	~dlist();

	void push_front(T);
	void push_back(T);
	T    front() const;
	T    remove_front();
	T	 back() const ;
	T    remove_back();
	uint length() const;
	T    get(uint) const;
	bool contains(T) const;
	bool empty() const;
	void clear();
	std::string to_string() const;
	void operator= (const dlist&);
};

/* Implementation of the dlink class */

template <class T>
dlink<T>::dlink(T val) 
	: value(val), previous(0), next(0) {}

template <class T>
dlink<T>::dlink(T val, dlink *prev, dlink* nxt) 
	: value(val), previous(prev), next() {}

/* Implementation of the dlist clas */

template <class T>
dlist<T>::dlist() 
	: head(0), tail(0), size(0) {}

template <class T>
dlist<T>::~dlist() {
	clear();
}

template <class T>
bool dlist<T>::empty() const {
	if (head == 0 && tail == 0) {
        return true;
	}
	return false;
}

template <class T>
uint dlist<T>::length() const {
	return size;
}

template <class T>
bool dlist<T>::contains(T val) const {
	dlink<T> *p;

	p = head;
	while (p != 0) {
		if (p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

template <class T>
T dlist<T>::front() const {
	if (empty()) {
		throw NoSuchElement();
	}
	return head->value;
}

template <class T>
void dlist<T>::push_front(T val) {
    dlink<T> *new_link;
    new_link = new dlink<T>(val);

    if (new_link == 0) {
        throw OutOfMemory();
	}
	
    if (empty()) {
        head = new_link;
        tail = new_link;
    } else {
        new_link->next = head;
        head->previous = new_link;
        head = new_link;
    }
    size++;
}

template <class T>
void dlist<T>::push_back(T val) {
    dlink<T> *new_link;
    new_link = new dlink<T>(val);

    if (new_link == 0) {
        throw OutOfMemory();
	}
	
    if (empty()) {
        head = new_link;
        tail = new_link;
    } else {
        new_link->previous = tail;
        tail->next= new_link;
        tail = new_link;
    }
    size++;
}

template <class T>
T dlist<T>::remove_front() {
    T val;
    dlink<T> *p;

    if (empty()) {
        throw NoSuchElement();
    }

    p = head;
    val = p->value;
    if (head == tail) {
        head = 0;
        tail = 0;
    } else {
        head = p->next;
        p->next->previous = 0;
    }
    delete p;
    size--;
    return val;
}

template <class T>
T dlist<T>::get(uint index) const {
	uint pos;
	dlink<T> *p;

	if (index >= size) {
		throw IndexOutOfBounds();
	}

	if (index == 0) {
		return front();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	return p->value;
}

template <class T>
void dlist<T>::clear() {
	dlink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

template <class T>
std::string dlist<T>::to_string() const {
	std::stringstream aux;
	dlink<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
void dlist<T>::copy(const dlist<T> &source) {
	dlink<T> *p, *q;

	if (source.empty()) {
		size = 0;
		head = 0;
		tail = 0;
	} else {
		p = source.head;
		head = new dlink<T>(p->value);
		if (head == 0) {
			throw OutOfMemory();
		}
		
		q = head;
		p = p->next;
		while(p != 0) {
			q->next = new dlink<T>(p->value, q, 0);
			if (q->next == 0) {
				throw OutOfMemory();
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

template <class T>
dlist<T>::dlist(const dlist<T> &source) {
	copy(source);
}

template <class T>
void dlist<T>::operator=(const dlist<T> &source) {
	clear();
	copy(source);
}
#endif /* DLIST_H_ */
