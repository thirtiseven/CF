#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>

unsigned T, n;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n-(n+3)/4; i++) {
			std::cout << "9";
		}
		for (int i = n-(n+3)/4; i < n; i++) {
			std::cout << "8";
		}
		std::cout << '\n';
	}
}