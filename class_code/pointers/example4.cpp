/**
    File: example4.cpp
    Purpose: Different exercises on pointer arithmetic.

    @author Pedro Perez
    @version 2.0 06/01/2020
*/
#include <iostream>

using namespace std;

const int SIZE = 10;

int main(int argc, char *argv[]) {
	int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int* ptr = &arr[0];
	cout << "arr[0]: " << arr[0] << "\n";
	cout << "ptr -> arr[0]:" << (*ptr) << "\n";
	cout << "value of prt " << ptr << "\n";
	
	/*
	for (ptr = &arr[0]; ptr != &arr[SIZE-1]; ptr++) {
		cout << (*ptr) << " - value of ptr: " << ptr << "\n";
	}
	*/
	
	cout << *(arr + 5) << "\n";
	cout << *(ptr + 5) << "\n";
	
	cout << 5[arr] << "\n";
}
