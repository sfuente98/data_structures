/**
    File: example0.cpp
    Purpose: The program declares an arrangement of 40,0000,000 integers. The program 
    compiles, but does not run, because a static array of the requested size cannot 
    be created.

    @author Pedro Perez
    @version 2.0 06/01/2020
*/

#include <iostream>

using namespace std;

const int SIZE = 40000000;

int main(int argc, char* argv[]) {
	int arr[SIZE];
	
	for (int i = 0; i < SIZE; i++) {
		arr[i] = i;
	}
	
	return 0;
}
