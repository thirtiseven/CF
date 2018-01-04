#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::cin >> n >> s;
	int ud = 0, lr = 0;
	for(int i = 0; i < s.length(); i++) {
		switch (s[i]) {
			case 'U':
				ud++;break;
			case 'D':
				ud--;break;
			case 'L':
				lr--;break;
			case 'R':
				lr++;break;
		}
	}
	std::cout << n - abs(ud) - abs(lr) << std::endl;
	return 0;
}