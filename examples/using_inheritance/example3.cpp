#include <iostream>

using namespace std;

/***************** FIGURE *****************/
class Figure {
protected:
	string type;
	
public:
	Figure();
	Figure(string);
	string getType() const;
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
};

Figure::Figure()
	:type("Figure") {
}

Figure::Figure(string t)
	:type(t) {
}

string Figure::getType() const {
	return type;
}

/***************** SQUARE *****************/
class Square : public Figure {
private:
	double side;
	
public:
	Square(double);
	double perimeter() const;
	double area() const;
};

Square::Square(double s) 
	: Figure("Square"), side(s) {
}

double Square::perimeter() const {
	return (4 * side);
}

double Square::area() const {
	return (side * side);
}

int main(int arc, char* argv[]) {
	Square sq(10);
	Figure *p = &sq;
	
	cout << "SQ:\n";
	cout << "type = " << sq.getType() << "\n";
	cout << "perimeter = " << sq.perimeter() << "\n";
	cout << "area = " << sq.area() << "\n";
	cout << "\n";
	
	cout << "P:\n";
	cout << "type = " << p->getType() << "\n";
	cout << "perimeter = " << p->perimeter() << "\n";
	cout << "area = " << p->area() << "\n";
	cout << "\n";
	return 0;
}
