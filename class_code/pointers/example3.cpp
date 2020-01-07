/**
    File: example3.cpp
    Purpose: The array is traversed using the arithmetic of the pointers.

    @author Pedro Perez
    @version 2.0 06/01/2020
*/
#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 400000000;

int main(int argc, char* argv[]) {
	int* arr, i;
	
	i = 1;
	arr = (int*) malloc(SIZE * sizeof(int));
	for (int* ptr = arr; ptr < (arr + SIZE); ptr++) {
		//arr[i] = i;
		*(ptr) = i++;
	}
	
	cout << "finish..." << "\n";
	free(arr);
	
	return 0;
}
