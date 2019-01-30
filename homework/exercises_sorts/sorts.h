/*
 * sorts.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef SORTS_H_
#define SORTS_H_

#include "../includes/exception.h"
#include <vector>
#include <list>

template <class T>
class sorts {
private:
	void swap(std::vector<T>&, int, int);
	
public:
	std::vector<T> bucket_sort(const std::vector<T>&);
	std::list<T>   merge_list(const std::list<T>&, const std::list<T>&);
};

template <class T>
void sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
std::vector<T> sorts<T>::bucket_sort(const std::vector<T> &source) {
	typename  std::list<T>::iterator itr;
	std::vector<T> v;

	return source;
}

template <class T>
std::list<T> sorts<T>::merge_list(const std::list<T> &lst1, const std::list<T> &lst2) {
	typename std::list<T>::const_iterator itr1, itr2;
	std::list<T> result;

	return result;
}

#endif /* SORTS_H_ */
