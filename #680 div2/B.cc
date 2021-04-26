#include <iostream>
#include <algorithm>

int t, a, b, c, d;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> a >> b >> c >> d;
		std::cout << std::max(a + b, c + d) << '\n';
	}
}