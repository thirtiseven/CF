#include <iostream>
#include <cmath>

double n, R, r;
const double pi = acos(-1.0);
const double eps = 1e-8;

int main(int argc, char *argv[]) {  
	std::cin >> n >> R >> r;
	if (r > R) {
		std::cout << "NO\n";
		exit(0);
	} else if (n == 1) {
		std::cout << "YES\n";
		exit(0);
	}
	if (pi / asin(r/(R-r)) > n-eps) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}