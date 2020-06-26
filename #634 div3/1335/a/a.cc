#include <iostream>

int t, n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		if (n <= 2) {
			std::cout << "0\n";
		} else {
			std::cout << (n+1)/2-1 << '\n';
		}
	}
}