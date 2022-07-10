#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

unsigned t, n;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::map<double, int> x;
	x[0.1]++;
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		if (n == 1) {
			std::cout << "3\n";
		} else if (__builtin_ctz(n) == 0) {
			std::cout << 1 << '\n';
		} else {
			unsigned x = (1 << __builtin_ctz(n));
			if (x == n) {
				x++;
			}
			std::cout << x << '\n';
		}
	}
}

//1111
//0001
//
//01
//11
//
//100000
//100001