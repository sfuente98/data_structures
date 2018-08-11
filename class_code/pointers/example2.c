#include <stdio.h>
#include <stdlib.h>

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
