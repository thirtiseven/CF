#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n;
	int odd = 0, even = 0, input;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> input;
		if (input % 2 == 1) {
			odd++;
		} else {
			even++;
		}
	}
	std::cout << std::min(even, odd);
}