#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int T, a, b;
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b;
		int x = std::abs(a-b);
		int ans = 0;
		ans += x/5;
		x %= 5;
		if (x == 1 || x == 2) {
			ans++;
		} else if (x == 3 || x == 4) {
			ans+=2;
		}
		std::cout << ans << '\n';
	}
}