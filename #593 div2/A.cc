#include <iostream>

int main(int argc, char *argv[]) {  
	int t, a, b, c;
	std::cin >> t;
	while (t--) {
		std::cin >> a >> b >> c;
		int ans = 0;
		ans += std::min(b, c/2);
		b -= ans;
		ans *= 3;
		ans += std::min(a, b/2)*3;
		std::cout << ans << '\n';
	}
}