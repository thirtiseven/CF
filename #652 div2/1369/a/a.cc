#include <iostream>
#include <algorithm>

int t, n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		if (n % 4 == 0) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}