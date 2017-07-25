#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char *argv[]) {  
	std::string a, b;
	std::cin >> a >> b;
	if(a == b) {
		std::cout << "-1\n";
	} else {
		std::cout << std::max(a.length(), b.length());
	}
	return 0;
}