#include <iostream>
#include <algorithm>

using ll = long long;

ll T, a, b, n, m;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b >> n >> m;
		if (n + m > a + b) {
			std::cout << "No\n";
			continue;
		}
		if (m <= std::min(a, b) && n <= std::max(a, b)) {
			std::cout << "Yes\n";
			continue;
		}
		if (n-m >= std::abs(a-b)) {
			std::cout << "Yes\n";
			continue;
		} else {
			std::cout << "No\n";
		}
		
	}
}