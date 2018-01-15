#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000

int main(int argc, char* argv[]) {
	int i, *arr;
	
	arr = (int*) malloc(sizeof(int) * MAX);
	for (i = 0; i < MAX; i++) {
		*(arr + i) = i;
	}
	
	for (i = 0; i < 20; i++) {
		printf("%i ", *(arr + i));
	}
	printf("\n");
	
	free(arr);
	return 0;
}
