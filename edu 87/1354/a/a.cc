#include <iostream>
#include <algorithm>

using ll = long long;

ll T, a, b, c, d;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b >> c >> d;
		if (b < a && c <= d) {
			std::cout << "-1\n";
		} else if (b >= a) {
			std::cout << b << '\n';
		} else {
			std::cout << b + (a-b+c-d-1)/(c-d) * c << '\n';
		}
	}
}