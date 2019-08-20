/*************************************************
 El programa declara un arreglo de 40,0000,000 de
 números enteros. El programa compila, pero no 
 corre, debido a que no se puede crear un arreglo
 estático del tamaño pedido.
**************************************************/
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
