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
	void copy_array(std::vector<T>&, std::vector<T>&, int, int);
	void merge(std::vector<T>&, std::vector<T>&, int, int, int);
	void split(std::vector<T>&, std::vector<T>&, int, int);
public:
	std::vector<T> bubble_sort(const std::vector<T>&);
	std::vector<T> selection_sort(const std::vector<T>&);
	std::vector<T> insertion_sort(const std::vector<T>&);
	std::vector<T> shell_sort(const std::vector<T>&);
	std::vector<T> merge_sort(const std::vector<T>&);
};

template <class T>
void sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
std::vector<T> sorts<T>::bubble_sort(const std::vector<T> &source) {
	std::vector<T> v(source);
	for(int i  = v.size() -1; i > 0; i--){
        for(int j = 0;  j<i; j++){
            if(v[j] > v[j+1]){
                swap(v, j, j+1);
            }
        }
	}
	return v;
}

template <class T>
std::vector<T> sorts<T>::selection_sort(const std::vector<T> &source) {
	std::vector<T> v(source);
    int pos;

    for(int i = v.size()-1; i > 0; i--){
        pos = 0;
        for(int j = 1; j <= i; j++){
            if(v[j] > v[pos]){
                pos = j;
            }
        }

        if (pos != i){
            swap(v,i,pos);
        }
    }
	return v;
}

template <class T>
std::vector<T> sorts<T>::insertion_sort(const std::vector<T> &source) {
	std::vector<T> v(source);

	for(int i = 1; i <v.size(); i++){
        for(int j = i; j > 0 && v[j]<v[j-1]; j--){
            swap(v, j, j-1);
        }
	}
	return v;
}

template <class T>
std::vector<T> sorts<T>::shell_sort(const std::vector<T> &source) {
	std::vector<T> v(source);
	int gap = v.size()/2;

	while(gap>0){
        for(int i = gap; i <v.size(); i++){
            for(int j = i; j >= gap && v[j] < v[j-gap]; j-=gap){
                swap(v,j,j-gap);
            }
        }
        gap /= 2;  // gap = gap /2;
	}
	return v;
}

template <class T>
void sorts<T>::copy_array(std::vector<T> &A, std::vector<T> &B, int low, int high) {
    for(int i = low;  i<=high; i++){
        A[i] = B[i];
    }
}

template <class T>
void sorts<T>::merge(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while(i<=mid && j<= high){
        if(A[i]< A[j]){
            B[k] = A[i];
            i++;
        }else{
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if( i > mid){
        for(; j <= high; j++){
            B[k++] = A[j];
        }
    }else{
        for(; i<= mid; i++){
            B[k++] = A[i];
        }
    }
}

template <class T>
void sorts<T>::split(std::vector<T> &A, std::vector<T> &B, int low, int high) {
    int  mid;

    if((high-low)< 1){
        return;
    }
    mid = (high+low)/2;
    split(A, B, low, mid);
    split(A, B, mid +1, high);
    merge(A, B,low, mid, high);
    copy_array(A,B, low, high);
}

template <class T>
std::vector<T> sorts<T>::merge_sort(const std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());
	split(v, tmp, 0,v.size()-1);
	return v;
}

template <class T>
long binary_search(const std::vector<T> &source, const T& val) {
	long low, high, mid;
	
	low = 0;
	high = source.size();
	while (low <= high) {
		mid = (high + low) / 2;
		if (val == source[mid]) {
			return mid;
		} else if (val < source[mid]) {
			high = mid - 1;
		} else if (val > source[mid]) {
			low = mid + 1;
		}
	}
	return -1;
}

#endif /* SORTS_H_ */
