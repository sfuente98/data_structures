/*
Given a linked list and a number k. The task is to print the
value of the k-th node from the middle towards the beginning
of the List. If no such element exists, then print “-1”.
*/
#include <iostream>
#include <list>

using namespace std;

int find_k_mid(const list<int> &lst, int k) {
	list<int>::const_iterator itr;
	
	int required = (lst.size() / 2) + 1 - k;
	int count = 1;
	
	if (required <= 0) {
		return -1;
	}
	
	itr = lst.begin();
	while (count != required) {
		itr++;
		count++;
	}
	return *itr;
}

template <class T>
void display_list(const char * text, const list<T> &lst) {
	typename  std::list<T>::const_iterator itr;
	
	cout << text << ": ";
	if (lst.empty()) {
		cout << "EMPTY\n";
		return;
	}
	
	itr = lst.begin();
	cout << *itr;
	itr++;
	while (itr != lst.end()) {
		cout << "->" << *itr;
		itr++;
	}
	cout << "\n";
}

template <class T>
std::list<T> create(T array[], int size) {
	list<T> result;
	
	for (int i = 0; i < size; i++) {
		result.push_back(array[i]);
	}
	return result;
}

int main(int argc, char* argv[]) {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	
	list<int> lst = create(array, 8);

	display_list("base: ", lst);
	cout << "k = 1 - " << find_k_mid(lst, 1) << "\n";
	cout << "k = 2 - " << find_k_mid(lst, 2) << "\n";
	cout << "k = 6 - " << find_k_mid(lst, 6) << "\n";
	return 0;
}
