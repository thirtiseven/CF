#include <iostream>

int t, sum1 = 0, sum2 = 0, n;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		sum1 += t;
	}
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		sum2 += t;
	}
	if (sum2 > sum1) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
	}
}