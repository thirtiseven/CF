#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int x = 0, y = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'U') {
			y++;
		} else if(s[i] == 'R') {
			x++;
		} else if(s[i] == 'D') {
			y--;
		} else if(s[i] == 'L') {
			x--;
		}
	}
	if(s.length() % 2 == 1) {
		std::cout << "-1";
	} else {
		std::cout << (abs(x) + abs(y)) / 2;
	}
	return 0;
}