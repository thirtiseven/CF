#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	int q;
	std::cin >> q;
	while (q--) {
		double n, t, sum = 0;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> t;
			sum += t;
		}
		sum/=n;
		std::cout << int(ceil(sum)) << '\n';
	}
}