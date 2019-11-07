#include <iostream>
#include <cmath>
#include <algorithm>

int n, t, tot = 0;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		if (std::abs(t)%2==1) {
			tot++;
//			std::cout << t << ' ' << tot << '\n';
			if (tot%2==1) {
				std::cout << int(ceil(double(t)/2.0)) << '\n';
			} else {
				std::cout << int(floor(double(t)/2.0)) << '\n';
			}
		} else {
			std::cout << t/2 << '\n';
		}
	}
}