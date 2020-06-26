#include <iostream>
#include <algorithm>

int n, m, t;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		if (n == 1) {
			std::cout << "0\n";
		} else if (n == 2) {
			std::cout << m << '\n';
		} else {
			std::cout << 2*m << '\n';
		}
	}
}