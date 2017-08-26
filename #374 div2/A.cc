#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::cin >> n >> s;
	int sum = 0;
	int b[100], bpos = 0;
	memset(b, 0, sizeof(b));
	for(int i = 0; i < n; i++) {
		if(s[i] == 'B') {
			b[bpos]++;
		} else {
			bpos++;
		}
	}
	for(int i = 0; i < n; i++) {
		if(b[i]) {
			sum++;
		}
	}
	std::cout << sum << "\n";
	for(int i = 0; i < n; i++) {
		if(b[i]) {
			std::cout << b[i] << " ";
		}
	}
	return 0;
}