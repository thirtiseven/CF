#include <iostream>

int main(int argc, char *argv[]) {  
	int t, a, b, c, d, k;
	std::cin >> t;
	while (t--) {
		std::cin >> a >> b >> c >> d >> k;
		if ((a-1)/c+1+(b-1)/d+1 <= k) {
			std::cout << (a-1)/c+1 << ' ' << (b-1)/d+1 << '\n';
		} else {
			std::cout << "-1\n";
		}
	}
}