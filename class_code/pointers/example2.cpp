/**
    File: example2.cpp
    Purpose: The program declares a dynamic 40,0000,000 array of integers. The 
    program compiles and runs correctly, since dynamic memory can create an array 
    of the requested size.
  	WE USE MALLOC AND FREE

    @author Pedro Perez
    @version 2.0 06/01/2020
*/

#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 40000000;

int main(int argc, char* argv[]) {
	int* arr;
	
	arr = (int*) malloc(SIZE * sizeof(int));
	for (int i = 0; i < SIZE; i++) {
		arr[i] = i;
	}
	
	for (int i = 0; i < 200; i++) {
		cout << arr[i] << " ";
	}
	free(arr);
	
	return 0;
}
