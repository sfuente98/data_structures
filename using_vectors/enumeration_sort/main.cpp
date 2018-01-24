#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1000;

int minimum(const int &a, const int &b) {
	return (a - b);
}

template <class T>
void enumerationSort(vector<T> &v, int (compare) (const T&, const T&)) {
	vector<T> temp(v.size());
	int count, result;
	
	for (int i = 0; i < v.size(); i++) {
		count = 0;
		for (int j = 0; j < v.size(); j++) {
			result = compare(v[j], v[i]);
			if (result < 0) {
				count++;
			} else if (result == 0 && j < i) {
				count++;
			}
		}
		temp[count] = v[i];
	}
	v = temp;
}

template <class T>
void display(const char* text, const vector<T> &v) {
	printf("%s: [", text);
	for (vector<int>::const_iterator it = v.begin() ; it != v.end(); ++it) {
		printf(" %i", (*it));
	}
	printf("]\n");
}

int main(int argc, char* argv[]) {
	vector<int> v;
	
	for (int i = MAX; i > 0; i--) {
		v.push_back(i);
	}
	
	display("before", v);
	
	enumerationSort(v, minimum);
	
	display("after", v);
	return 0;
}
