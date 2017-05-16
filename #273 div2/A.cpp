#include <iostream>

int main(int argc, char *argv[]) {
	int c1, c2, c3, c4, c5;
	std::cin >> c1 >> c2 >> c3 >> c4 >> c5;
	int sum = c1 + c2 + c3 + c4 + c5;
	if(sum % 5 != 0 || sum == 0) {
		std::cout << "-1" << std::endl;
	} else {
		std::cout << sum / 5 << std::endl;
	}
	return 0;
}