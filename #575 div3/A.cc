#include <iostream>

int main(int argc, char *argv[]) { 
	int T;
	std::cin >> T;
	while (T--) {
		long long a, b, c;
		std::cin >> a >> b >> c;
		std::cout << (a+b+c)/2 << '\n';
	} 
}