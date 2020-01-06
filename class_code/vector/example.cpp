#include <iostream>
#include "vector.h"

using namespace std;

int main(int argc, char* argv[]) {
	float x = 0.1;
	vector<int> a(5);
	vector<float> b(10, x);

	cout << "a:" << a.to_string() << "\n";
	for (unsigned int i = 0; i < a.length(); i++) {
		a[i] = 2 * (i + 1);
	}
	cout << "a:" << a.to_string() << "\n";

	vector<int> c(15);
	cout << "c:" << c.to_string() << "\n";
	c = a;
	cout << "c:" << c.to_string() << "\n";

	return 0;
}
