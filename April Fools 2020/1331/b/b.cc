#include <iostream>

int x;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> x;
	for (int i = 2; i <= x; i++) {
		if (x % i == 0) {
			std::cout << i << x/i << '\n';
			break;
		}
	}
}