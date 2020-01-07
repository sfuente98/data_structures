/**
    File: recursion.h
    Purpose: Different examples of recursive functions and. iterative functions

    @author Pedro Perez
    @version 2.0 06/01/2020
*/
#ifndef RECURSION_H_
#define RECURSION_H_

#include "../includes/exception.h"
#include <iostream>

typedef unsigned long int uli;
typedef unsigned int ui;

/**
	Calculate the sum of all numbers from 1 to N iteratively.
	
	@param N an integer number.
	@return the sum of all number from 1 to N
*/
uli sum_seq(int N) {
    uli acum = 0;
    for (int i = 1; i <= N; i++) {
       acum = acum + i;
    }
	return acum;
}

/**
	Calculate the sum of all numbers from 1 to N recursively.
	
	@param N an integer number.
	@return the sum of all number from 1 to N
*/
uli sum_rec(int N) {
    if(N <= 0) {
        return  0;
    } else {
        return N + sum_rec(N - 1);
	}
}

/**
	Calculate the factorial of N iteratively.
	
	@param N an integer number.
	@return the factorial of N.
*/
uli fact_seq(int N) {
	uli acum = 1;

    if (N <= 0) {
        return -1;
    }

    for (int i = 1; i <= N; i++) {
        acum *= i;
    }
	return acum;
}

/**
	Calculate the factorial of N recursively.
	
	@param N an integer number.
	@return the sum of all number from 1 to N
*/
uli fact_rec(int n) {
    if (n<0) {
        return -1;
	}

    if (n<=1) {
        return 1;
    } else {
        return n* fact_rec(n-1);
	}
}

/**
	Calculate the nth number of the Fibonacci sequence iteratively.
	
	@param n an integer number.
	@return the the nth number of the Fibonacci.
*/
uli fib_seq(int n) {
    uli a, b, aux;
	int i;

	if (n == 1 || n == 2) {
        return 1;
	}

    a = 1;
    b = 1;
    i = 3;
    while (i <= n) {
        aux = a + b;
        a = b;
        b = aux;
        i++;
    }
    return b;
}

/**
	Calculate the nth number of the Fibonacci sequence recursively.
	
	@param n an integer number.
	@return the the nth number of the Fibonacci.
*/
uli fib_rec(int n) {
    if (n <= 0) {
        return -1;
	}

    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib_rec(n-1)+ fib_rec(n-2);
	}
}

/**
	Calculate the greatest common divisor of a and b iteratively.
	
	@param a, b unsigned long integer numbers.
	@return the the greatest common divisor.
*/
uli gcd_seq(uli a, uli b) {
    uli aux;
    while (b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }
	return a;
}

/**
	Calculate the greatest common divisor of a and b recursively.
	
	@param a, b unsigned long integer numbers.
	@return the the greatest common divisor.
*/
uli gcd_rec(uli a, uli b) {
    if (b == 0) {
        return a;
    } else {
        return gcd_rec(b, a % b);
	}
}

/**
	Detects whether an item is in an array or not iteratively.
	
	@param arr an integer array 
	@param size the number of items in the array.
	@param val the elemento to find.
	@return true if the item, val, is within the array; false otherwise.
*/
bool find_seq(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (val == arr[i]) {
            return true;
		}
    }
	return false;
}

/**
	Detects whether an item is in an array or not recursively.
	
	@param arr an integer array 
	@param low lower limit of the search.
	@param high upper limit of the search.
	@param val the elemento to find.
	@return true if the item, val, is within the array; false otherwise.
*/
bool find_rec(int arr[], int low, int high, int val) {
    ui mid;
    bool aux;

    if ((high - low + 1) == 1) {
        return (val == arr[low]);
    }else{
        aux = false;
        mid = low + (high - low) / 2;
        aux = find_rec(arr, low, mid, val);
        if (!aux) {
            aux = find_rec(arr, mid +1, high, val);
        }
        return aux;
    }
}

/**
	Return the maximum element of the array iteratively.
	
	@param arr an integer array 
	@param size the number of items in the array.
	@return the maximum element
*/
int max_seq(int arr[], int size) {
    int m = arr[0];

    for (int i  = 1; i < size; i++) {
        if(m<arr[i]){
            m = arr[i];
        }
    }
	return m;
}

/**
	Return the maximum element of the array recursively.
	
	@param arr an integer array 
	@param pos the position being reviewed.
	@return the maximum element
*/
int max_rec(int arr[], int pos) {
	if (pos == 0) {
		return arr[0];
	} else {
		int mprev = max_rec(arr, pos - 1);
		return ((arr[pos] > mprev)? arr[pos] : mprev);
	}
}

/**
	Detects whether an item is in an array or not using a cycle and divide 
	and conquer strategy. 
	
	@param arr an integer array 
	@param size the number of items in the array.
	@param val the elemento to find.
	@return the position in the array in which the element, val, is.
*/
int bs_seq(int arr[], int size, int val) {
    int mid;
    int low = 0;
    int high = size -1;

    while (low < high) {
        mid = (high + low)/2;
        if(val == arr[mid]) {
            return mid;
        } else if (val < arr[mid]) {
            high = mid - 1;
        } else if (val > arr[mid]) {
            low = mid + 1;
        }
    }
	return low;
}

/**
	Auxiliary function that detects whether an item is in an array or not.
	
	@param arr an integer array 
	@param low lower limit of the search.
	@param high upper limit of the search.
	@param val the elemento to find.
	@return the position in the array in which the element, val, is.
*/
int bs_aux(int arr[], int low, int high, int val) {
	int mid;

	if (low > high) {
		return low;
	} else {
		mid = (high + low)/2;
        if(val == arr[mid]) {
            return mid;
        } else if (val < arr[mid]) {
            return bs_aux(arr, low, mid - 1, val);
        } else if (val > arr[mid]) {
            return bs_aux(arr, mid + 1, high, val);
        }
	}
}

/**
	Detects whether an item is in an array or not using recursion and 
	divide and conquer strategy. 
	
	@param arr an integer array 
	@param size the number of items in the array.
	@param val the elemento to find.
	@return the position in the array in which the element, val, is.
*/
int bs_rec(int arr[], int size, int val) {
	return bs_aux(arr, 0, size - 1, val);
}
#endif /* RECURSION_H_ */
