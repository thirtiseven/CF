#include <iostream>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	long long a, b;
	while (T--) {
		std::cin >> a >> b;
		if (a-b == 1) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
		}
	}
}