#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		if (s.length() > 10) {
			std::cout << s[0] << s.length()-2 << s[s.length()-1] << std::endl;
		} else {
			std::cout << s << std::endl;
		}
	}
}