#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool minimum(int i, int j) { 
	return i < j; 
}

int countSpaces(char* line) {
	int low, high, result;
	
	low = 0;
	high = 24;
	
	while (line[low] == 'X') {
		low++;
	}
	
	while (line[high] == 'X') {
		high--;
	}
	
	result = high - low + 1;
	return (result < 0)? 0 : result;
}
		

int main(int argc, char* argv[]) {
	vector<int> spaces;
	char line[26];
	int n, min, acum;
	
	while (1) {
		scanf("%i%*c", &n);
		if (n == 0) {
			break;
		}
		
		spaces.clear();
		for (int i = 0; i < n; i++) {
			fgets(line, 26, stdin); scanf("%*c");
			spaces.push_back(countSpaces(line));
		}
		
		sort(spaces.begin(), spaces.end(), minimum);
		min = spaces[0];
		acum = 0;
		for (vector<int>::iterator it = spaces.begin() ; it != spaces.end(); ++it) {
			acum += (*it) - min ;
		}
		printf("%i\n", acum);
	}
		
	return 0;
}
		
