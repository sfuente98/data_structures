/**
    File: example5.cpp
    Purpose: Examples of passing parameters by value, 
    by pointer and by reference.

    @author Pedro Perez
    @version 2.0 06/01/2020
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

void swap1(int a, int b) {
	int aux = a;
	a = b;
	b = aux;
	printf("SWAP a = %i - b = %i\n", a ,b);
}

void swap2(int *a, int *b) {
	int aux = (*a);
	(*a) = (*b);
	(*b) = aux;
	printf("SWAP2 a = %i - b = %i\n", *a, *b);
}


void swap3(int &a, int &b) {
	int aux = a;
	a = b;
	b = aux;
	printf("SWAP2 a = %i - b = %i\n", a, b);
}

int main(int argc, char* argv[]) {
	int a, b;
	
	a = 10;
	b = 15;
	printf("ANTES a = %i - b = %i\n", a ,b);
	printf("DESPUES a = %i - b = %i\n", a ,b);
	
	return 0;
}
