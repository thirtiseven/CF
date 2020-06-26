#include <iostream>
#include <algorithm>

using ll = long long;

ll T, a, b, c;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b >> c;
		if (a >= c) {
			std::cout << "-1 ";
		} else {
			std::cout << "1 ";
		}
		if (a*b > c) {
			std::cout << b << '\n';
		} else {
			std::cout << "-1\n";
		}
	}
}