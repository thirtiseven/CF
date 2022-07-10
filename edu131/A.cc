#include <iostream>
#include <algorithm>

int t, a, b, c, d;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> a >> b >> c >> d;
		if (a + b + c + d == 0) {
			std::cout << "0\n";
		} else if (a + b + c + d == 4) {
			std::cout << "2\n";
		} else {
			std::cout << "1\n";
		}
	}
}