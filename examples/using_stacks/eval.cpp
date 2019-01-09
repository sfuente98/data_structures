#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <queue>
#include <stack>
#include "exception.h"

using namespace std;


queue<string> tokenize(string str) {
	int i = 0;
	int length = str.size();
	string aux;
	queue<string> result;

	while (i < length) {
		if (isdigit(str[i])) {
			aux.clear();
			do {
				aux += str[i];
				i++;
			} while(isdigit(str[i]));
			result.push(aux);
		} else if (isspace(str[i])) {
			i++;
		} else {
			aux.clear();
			aux += str[i];
			result.push(aux);
			i++;
		}
	}
	return result;
}

float evalPostfijo(string str) {
	stack<float> s;
	queue<string> q;
	string element, a;
	float left, right, result;
	
	q = tokenize(str);
	while (!q.empty()) {
		element = q.front(); q.pop();
		if (element == "+" || element == "-" || 
		    element == "*" || element == "/") {
			if (s.empty()) {
				throw NoSuchElement();
			}
			right = s.top(); s.pop();
			if (s.empty()) {
				throw NoSuchElement();
			}
			left = s.top(); s.pop();
			switch (element[0]) {
				case '+': result = left + right; break;
				case '-': result = left - right; break;
				case '*': result = left * right; break;
				case '/': result = left / right; break;
			}
			s.push(result);
		} else {
			result = (float) atof(element.c_str());
			s.push(result);
		}
	}
	return s.top();
}

int evalInfijo(string str) {
	queue<string> elements;
	stack<char> operators;
	stack<int> results;
	string ele;
	
	elements = tokenize(str);
	while (!elements.empty()) {
		ele = elements.front(); elements.pop();
		if (ele == "(" || ele == "+" || ele == "-" ||
			ele == "*" || ele == "/") {
			operators.push(ele[0]);
		} else if (ele == ")") {
			char op;
			int left, right;
			
			while ( (op = operators.top()) != '(') {
				operators.pop();
				if (results.empty()) {
					throw NoSuchElement();
				}
				right = results.top(); results.pop();
				if (results.empty()) {
					throw NoSuchElement();
				}
				left = results.top(); results.pop();
				
				switch(op) {
					case '+' : results.push(left + right); break;
					case '-' : results.push(left - right); break;
					case '*' : results.push(left * right); break;
					case '/' : results.push(left / right); break;
				}
			}
			operators.pop();
		} else {
			results.push(atoi(ele.c_str()));
		} 
	}
	
	if (!operators.empty()) {
		throw Exception();
	}
	
	if (results.empty()) {
		throw Exception();
	}
	
	int r = results.top(); results.pop();
	if (!results.empty()) {
		throw Exception();
	}
	
	return r;
}

int main(int argc, char* argv[]) {
	string aux = "3 4 + 8 * 5 4 / -";
	float result = eval(aux);
	cout << "aux = " << result << "\n";
	
	aux = "0 3 - 8 * 5 4 / -";
	result = eval(aux);
	cout << "aux = " << result << "\n";
	
	aux = "3 + 8 * 5 4 / -";
	result = eval(aux);
	cout << "aux = " << result << "\n";
	
	return 0;
}


