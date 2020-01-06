/**
    File: using_rational.cpp
    Purpose: This file uses the rational class in different operations.

    @author Pedro Perez
    @version 2.0 06/01/2020
*/
#include <iostream>
#include "../implementation/rational.h"

using namespace std;

int main(int argc, char* argv[]) {
	rational a, b(5), c(18, 24);

	cout << "a = " << a.to_string() << " b = " << b.to_string() << " c = " << c.to_string() << "\n";
	a = b;
	cout << "a = " << a.to_string() << " b = " << b.to_string() << " c = " << c.to_string() << "\n";
	a += c;
	cout << "a = " << a.to_string() << " b = " << b.to_string() << " c = " << c.to_string() << "\n";

	rational d;
	d = a + c;
	cout << "d = " << d.to_string() << "\n";

	if (a < b) {
		cout << "a is less than b";
	} else {
		cout << "a is not less than b";
	}
	cout << "\n";

	return 0;
}
