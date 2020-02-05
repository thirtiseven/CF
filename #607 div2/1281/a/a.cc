#include <iostream>
#include <string>

int T;
std::string s;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		if (s.substr(s.length()-2) == "po") {
			std::cout << "FILIPINO" << '\n';
		} else if (s.substr(s.length()-4) == "desu" || s.substr(s.length()-4) == "masu") {
			std::cout << "JAPANESE" << '\n';
		}  else if (s.substr(s.length()-5) == "mnida") {
			std::cout << "KOREAN" << '\n';
		}
	}
}