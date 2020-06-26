#include <iostream>
#include <algorithm>

int T, n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		std::cout << n/2 << '\n';
	}
}