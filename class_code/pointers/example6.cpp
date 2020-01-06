/*************************************************
 Ejemplo de uso de apuntadores para enviar una 
 función como parámetro. En este caso, se realiza
 una técnica de integración basada en rectángulos.
 La función 'integration' recibe como parámetro 
 la función que se integra.
**************************************************/
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

#define RECTS 1e7

double integration(double (*fn) (double), double a, double b) {
	double acum, delta;
	
	acum = 0;
	if (a <= b) {
		delta = (b - a) / RECTS;
		for (int i = 0; i < RECTS; i++) {
			acum += (delta * fn(a + (i * delta)));
		}
	}
	return acum;
}

double x2 (double x) {
	return x * x;
}

double x3 (double x) {
	return x * x  *x;
}

int main(int argc, char* argv[]) {
	printf("x2[1, 100] = %lf\n", integration(x2, 1, 100));
	printf("x3[1, 100] = %lf\n", integration(x3, 1, 100));
	printf("sin[0, 1] = %lf\n", integration(sin, 0, 1));
	printf("cos[0, 1] = %lf\n", integration(cos, 0, 1));
	
	return 0;
}
