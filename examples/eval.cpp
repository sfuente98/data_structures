#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	stack<float> s;
	string input;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s.push( s[i] - '0' );
		} else if (s[i] == '+' || s[i] == '-'|| s[i] == '*' || s[i] == '/') {
			float der = s.top(); s.pop();
			float izq = s.top(); s.pop();
			switch(s[i]) {
				case '+' : s.push(izq + der); break;
				case '-' : s.push(izq - der); break;
				case '*' : s.push(izq * der); break;
				case '/' : s.push(izq / der); break;
			}
		}

	}
	return 0;
}
