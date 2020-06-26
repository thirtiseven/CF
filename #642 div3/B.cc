#include <iostream>
#include <algorithm>

int t, n, k, a[32], b[32];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		std::sort(a, a+n);
		std::sort(b, b+n);
		std::reverse(b, b+n);
		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += std::max(a[i], b[i]);
		}
		for (int i = k; i < n; i++) {
			sum += a[i];
		}
		std::cout << sum << '\n';
	}
}