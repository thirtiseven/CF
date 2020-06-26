#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int q, n, t[maxn], k, c[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> q;
	while (q--) {
		std::cin >> n;
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			std::cin >> t[i];
		}
		bool yes = 0;
		for (int i = 1; i < n; i++) {
			if (t[i] == t[i-1]) {
				yes = 1;
			} else {
				cnt++;
			}
		}
		int ans;
		if (cnt == 1) {
//			std::cout << "1\n";
			ans = 1;
			for (int i = 0; i < n; i++) {
				c[i] = 1;
			}
		} else if (cnt % 2 == 1) {
			if (yes) {
//				std::cout << "2\n";
				ans = 2;
				c[0] = 1;
				for (int i = 1; i < n; i++) {
					if (t[i] != t[i-1]) {
						c[i] = 3-c[i-1];
					} else {
						if (yes) {
							c[i] = 3-c[i-1];
							yes = 0;
						} else {
							c[i] = c[i-1];
						}
					}
				}
			} else {
//				std::cout << "3\n";
				ans = 3;
				c[0] = 1;
				for (int i = 1; i < n; i++) {
					if (t[i] != t[i-1]) {
						c[i] = 3-c[i-1];
					} else {
						c[i] = c[i-1];
					}
				}
				if (t[0] == t[n-1]) {
					ans = 2;
				} else {
					c[n-1] = 3;
				}
			}
		} else {
//			std::cout << "4\n";
			ans = 2;
			c[0] = 1;
			for (int i = 1; i < n; i++) {
				if (t[i] != t[i-1]) {
					c[i] = 3-c[i-1];
				} else {
					c[i] = c[i-1];
				}
			}
		}
		std::cout << ans << '\n';
		for (int i = 0; i < n; i++) {
			std::cout << c[i] << " \n"[i==n-1];
		}
	}
}