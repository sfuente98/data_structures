/*************************************************
 El programa declara un arreglo de 40,0000,000 
 dinámico de números enteros. El programa compila 
 y se ejecuta correctamente, ya que la memoria
 dinámica si puede crear un arreglo del tamaño 
 pedido.
 SE USA NEW Y DELETE
**************************************************/
#include <iostream>

using namespace std;

const int SIZE = 40000000;

int main(int argc, char* argv[]) {
	int* arr;
	
	arr = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		arr[i] = i;
	}
	
	for (int i = 0; i < 200; i++) {
		cout << arr[i] << " ";
	}
	delete [] arr;
	
	return 0;
}
