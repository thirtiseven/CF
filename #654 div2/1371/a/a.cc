#include <iostream>
#include <algorithm>

int T, a;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a;
		std::cout << (a+1)/2 << '\n';
	}
}