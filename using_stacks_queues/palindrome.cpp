#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool isPalindrome(string str) {
	queue<char> q;
	stack<char> s;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ') {
			q.push(str[i]);
			s.push(str[i]);
		}
	}
	
	while (!s.empty()) {
		if (q.front() != s.top()) {
			return false;
		}
		q.pop(); s.pop();
	}
	return true;
}

int main(int argc, char* argv[]) {
	/*
	string aux = "3 4 + 8 * 5 4 / -";
	float result = eval(aux);
	cout << "aux = " << result << "\n";
	
	aux = "0 3 - 8 * 5 4 / -";
	result = eval(aux);
	cout << "aux = " << result << "\n";
	
	aux = "3 + 8 * 5 4 / -";
	result = eval(aux);
	cout << "aux = " << result << "\n";
	*/
	
	/*
	string aux = "( ( 4 * 3 ) - ( 5 / ( 1 + 1 - 0 ) ) )";
	int result = evalInfijo(aux);
	cout << "aux = " << result << "\n";
	*/
	
	cout << "result = " << isPalindrome("el abad arroz a la zorra dabale") << endl;
	cout << "result = " << isPalindrome("esto no es un palindromo") << endl;
	return 0;
}


