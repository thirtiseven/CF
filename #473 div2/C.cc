#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	if (n <= 5) {
		std::cout << "-1\n";
	} else {
		std::cout << "1 2\n1 3\n1 4\n";
		for (int i = 5; i <= n; i++) {
			std::cout << "3 " << i << '\n';
		}
	}
	for (int i = 2; i <= n; i++) {
		std::cout << "1 " << i << '\n';
	}
	
}