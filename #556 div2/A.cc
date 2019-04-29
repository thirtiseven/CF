#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	int a1 = 0, a2 = 0;
	int temp;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		if (temp == 1) {
			a1++;
		} else {
			a2++;
		}
	}
	if (a2 > 0) {
		std::cout << "2 ";
		a2--;
	}
	if (a1 > 0) {
		std::cout << "1 ";
		a1--;
	}
	for (int i = 0; i < a2; i++) {
		std::cout << "2 ";
	}
	for (int i = 0; i < a1; i++) {
		std::cout << "1 ";
	}
	std::cout << "\n";
}