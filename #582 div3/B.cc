#include <iostream>
#include <algorithm>

int t, n, a[150006];

int main(int argc, char *argv[]) {  
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int minn = a[n-1];
		int ans = 0;
		for (int i = n-2; i >= 0; i--) {
			if (a[i] > minn) {
				ans++;
			}
			minn = std::min(a[i], minn);
		}
		std::cout << ans << '\n';
	}
}