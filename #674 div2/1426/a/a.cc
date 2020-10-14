#include <iostream>
#include <algorithm>

int t, n, x;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> x;
		int ans = 1;
		if (n <= 2) {
			ans = 1;
		} else {
			n -= 2;
			ans += ((n-1)/x)+1;
		}
		std::cout << ans << '\n';
	}
}