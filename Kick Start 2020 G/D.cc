#include <iostream>
#include <algorithm>

using ll = long long;

ll t, n, a;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	for (int CA = 1; CA <= t; CA++) {
		std::cin >> n >> a;
		std::cout << "Case #" << CA << ": ";
		if (n == 3) {
			std::cout << "POSSIBLE\n";
			std::cout << "0 0\n1 0\n1 " << a << '\n';
		} else if (n == 4) {
			if (a == 1) {
				std::cout << "IMPOSSIBLE\n";
			} else {
				std::cout << "POSSIBLE\n";
				std::cout << "0 0\n1 0\n1 " << a-2+1 << "\n0 1\n";
			}
		} else {
			if (a < 3) {
				std::cout << "IMPOSSIBLE\n";
			} else {
				std::cout << "POSSIBLE\n";
				std::cout << "0 1\n1 0\n1 1\n" << a-2+1 << " 1\n1 2\n";
			}
		}
	}
}