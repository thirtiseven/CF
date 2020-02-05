#include <iostream>

int n, t;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		if (n%2==1) {
			std::cout << '7';
			n-=3;
		}
		for (int i = 0; i < n/2; i++) {
			std::cout << '1';
		}	
		std::cout << '\n';
	}
}