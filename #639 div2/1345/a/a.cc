#include <iostream>

int T, a, b;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b;
		if ((a == b && b == 2) || (a == 1 || b == 1)) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}