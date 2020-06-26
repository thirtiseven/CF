#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int t, n, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		int ans = 1;
		for (int i = n-1; i >= 0; i--) {
			if (a[i] <= i+1) {
				ans = i+2;
				break;
			}
		}
		std::cout << ans << '\n';
	}
}