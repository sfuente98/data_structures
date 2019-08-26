#include <iostream>
#include "complex.h"

using namespace std;

int main(int argc, char* argv[]) {
  Complex a, b(12), c(1, 2);

  cout << a.toString() << " " << b.toString() << " " << c.toString() << "\n";
  a = b;
  cout << a.toString() << " " << b.toString() << " " << c.toString() << "\n";
  a += c;
  cout << a.toString() << " " << b.toString() << " " << c.toString() << "\n";

  Complex d;
  d = a + c;
  cout << "d: " << d.toString() << "\n";

  if (a < b) {
    cout << "es menor";
  } else {
    cout << "no lo es";
  }
  cout << "\n";

  return 0;
}
