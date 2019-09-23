#include <iostream>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int b, p, f, h, c;
		std::cin >> b >> p >> f >> h >> c;
		int ans = 0;
		if (h > c) {
			ans += std::min(b/2, p)*h;
			b -= std::min(b/2, p)*2;
			ans += std::min(b/2, f)*c;
		} else {
			ans += std::min(b/2, f)*c;
			b -= std::min(b/2, f)*2;
			ans += std::min(b/2, p)*h;
		}
		std::cout << ans << '\n';
	}
}