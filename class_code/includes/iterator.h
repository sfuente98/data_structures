/*
 * iterator.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "../includes/exception.h"

template <class T>
class iterator {
	virtual iterator& operator= (const iterator&) = 0;
	virtual iterator& operator++() = 0;
    virtual reference operator* () const = 0;
