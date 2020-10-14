#include <iostream>
#include <algorithm>

int T, n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		if (n < 31) {
			std::cout << "NO\n";
			continue;
		}
		std::cout << "YES\n";
		if (n-30==6 || n-30==10 || n-30==14) {
			std::cout << "6 10 15 " << n-31 << '\n';
		} else {
			std::cout << "6 10 14 " << n-30 << '\n';
		}
	}
}