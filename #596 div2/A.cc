#include <iostream>

int main(int argc, char *argv[]) {  
	int a, b;
	std::cin >> a >> b;
	if (a == b) {
		std::cout << a << '0' << ' ' << b << '1' << '\n';
	} else if (a == b-1) {
		std::cout << a << '9' << ' ' << b << '0' << '\n';
	} else if (a == 9 && b == 1) {
		std::cout << "99 100\n";
	} else {
		std::cout << "-1\n";
	}
}