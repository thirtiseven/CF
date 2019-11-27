#include <iostream>

int T, a, b;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b;
		bool yes = 1;
		if (a == 1 && b != 1) {
			yes = 0;
		} else if ((a == 2 || a == 3) && b >= 4) {
			yes = 0;
		}
		std::cout << (yes?"YES\n":"NO\n");
	}
}