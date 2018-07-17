#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int one = 0, zero = 0, isz = 1, two;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			one++;
		}
		if (isz && s[i] == '0') {
			zero++;
		}
		if (isz && s[i] == '2') {
			isz = 0;
			two = i;
		}
 	}
	for (int i = 0; i < zero; i++) {
		std::cout << '0';
	}
	for (int i = 0; i < one; i++) {
		std::cout << '1';
	}
	for (int i = two; i < s.length(); i++) {
		if (s[i] == '0' || s[i] == '2')
		std::cout << s[i];
	}
}