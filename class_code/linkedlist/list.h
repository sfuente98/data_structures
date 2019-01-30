/*
 * linkedlist.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <sstream>
#include "../includes/exception.h"

typedef unsigned int uint;

template <class T> class list;

/* Definition of the link class */
template <class T>
class link {
private:
	link(T);
	link(T, link<T>*);
	//link(const link<T>&);

	T	    value;
	link<T> *next;

	friend class list<T>;
};

/* Definition of the list class */
template <class T>
class list {
private:
	link<T> *head;
	uint 	size;
	
	void copy(const list<T>&);
	
public:
	list();
	list(const list<T>&);
	~list();

	void push_front(T);
	void push_back(T);
	T    front() const;
	T    pop_front();
	uint  length() const;
	T    get(uint) const;
	bool contains(T) const;
	bool empty() const;
	void clear();
	std::string to_string() const;
	void operator= (const list&);

	bool set(uint, T);
	uint  index_of(T) const;
	uint  last_index(T) const;
	T    remove(uint);
	bool remove_first_ocurrence(T);
	bool remove_last_ocurrence(T);
};


/* Implementation of the methods of the link class */
template <class T>
link<T>::link(T val) 
	: value(val), next(0) {}

template <class T>
link<T>::link(T val, link* nxt) 
	: value(val), next(nxt) {}

/*
template <class T>
link<T>::link(const link<T> &source) { value = source.value; next = source.next;}
*/

/* Implementation of the methods of the link class */
template <class T>
list<T>::list()
	:head(0), size(0) {}

template <class T>
list<T>::~list() {
    clear();
}

template <class T>
bool list<T>::empty() const {
	return (head == 0);
}

template <class T>
uint list<T>::length() const {
	return size;
}

template <class T>
bool list<T>::contains(T val) const {
	link<T> *p;

    p = head;
    while (p != 0) {
		if(p->value == val) {
			return true;
		}
		p = p->next;
    }
	return false;
}

template <class T>
T list<T>::front() const {
	if (empty()) {
		throw NoSuchElement();
	}
	
	return head->value;
}

template <class T>
void list<T>::push_front(T val) {
	
    link<T>  *new_link;

    new_link = new link<T>(val);
    if (new_link == 0) {
        throw OutOfMemory();
    }
    
    new_link->next = head;
    head = new_link;
    size++;
}

template <class T>
void list<T>::push_back(T val) {

    if (empty()) {
        push_front(val);
        return;
    }

	link<T> *p;
    p = head;
    while (p->next != 0) { 
          p = p->next;
    }
    
    link<T> *new_link;
    new_link = new link<T>(val);
    if (new_link == 0) {
        throw OutOfMemory();
    }
    
    new_link->next = p->next;
    p->next = new_link;
    size++;
}

template <class T>
T list<T>::pop_front() {
	T val;
	link<T> *p;

	if (empty()) {
        throw NoSuchElement();
	}
	
    p = head;

    head = p->next;
    val = p->value;

    delete p;
    size--;
	return val;
}

template <class T>
T list<T>::get(uint index) const {
    uint pos;
    link<T> *p;

    if (index >= size) {
        throw IndexOutOfBounds();
    }
    
    if (empty()) {
        throw NoSuchElement();
    }
    
    if (index == 0) {
        return front();
	}
	
    p = head;
    pos = 0;
    while (pos != index){
        p = p->next;
        pos++;
    }
    return p->value;
}

template <class T>
void list<T>::clear() {
    link<T> *p, *q;

    p = head;
    while (p != 0){
        q = p->next;
        delete p;
        p = q;
    }
    
    head = 0;
    size = 0;
}

template <class T>
std::string list<T>::to_string() const {
	std::stringstream aux;
	link<T> *p;

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
void list<T>::copy(const list<T> &source) {
	link<T> *p, *q;
	
	if (source.empty()) {
        head = 0;
        size = 0;
    } else {
		p = source.head;
		head = new link<T>(p->value);
		if (head == 0) {
		    throw OutOfMemory();
		}
		
		q = head;
		p = p->next;
		while (p != 0) {
		    q->next = new link<T>(p->value);
		    if(q->next == 0){
		        throw OutOfMemory();
		    }
		    p=p->next;
		    q=q->next;
		}
		size = source.size;
    }
}

template <class T>
list<T>::list(const list<T> &source) {
	copy(source);
}

template <class T>
void list<T>::operator=(const list<T> &source) {
	clear();
	copy(source);
}

template <class T>
bool list<T>::set(uint index, T val) {
}

template <class T>
uint list<T>::index_of(T val) const {
	return -1;
}

template <class T>
uint list<T>::last_index(T val) const {
    return -1;
}

template <class T>
T list<T>::remove(uint index) {
	T val;
	
	return val;
}

template <class T>
bool list<T>::remove_first_ocurrence(T val) {
    return false;
}

template <class T>
bool list<T>::remove_last_ocurrence(T val) {
	return false;
}

#endif /* LINKEDLIST_H_ */
