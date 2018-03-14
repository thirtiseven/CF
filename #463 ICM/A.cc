#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	std::cout << s;
	for (int i = s.length()-1; i >= 0; i--) {
		std::cout << s[i];
	}
}