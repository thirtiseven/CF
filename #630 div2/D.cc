#include <iostream>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int k;
	std::cin >> k;
	int x = 2;
	while (x <= k) {
		x *= 2;
	}
	std::cout << "3 4\n";
	std::cout << x+k << ' ' << k << ' ' << k << ' ' << 0 << '\n';
	std::cout << x << ' ' << 0 << ' ' << k << ' ' << 0 << '\n';
	std::cout << x << ' ' << x << ' ' << x+k << ' ' << k << '\n';
}