#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 123;

int T, n, m, p[maxn], a[maxn], b[maxn], c[maxn], vis[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::fill(vis, vis+n+3, 0);
		std::cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			b[i] = c[i] = a[i];
		}
		for (int i = 1; i <= m; i++) {
			std::cin >> p[i];
			vis[p[i]] = 1;
		}
		std::sort(b+1, b+n+1);
		int x = 1;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) {
				int x = i+1;
				while (vis[x]) {
					x++;
				}
//				std::cout << i << ' ' << x << '\n';
				std::sort(c+i, c+x+1);
			}
		}
		bool yes = 1;
//		for (int i = 1; i <= n; i++) {
//			std::cout << b[i] << ' ' << c[i] << '\n';
//		}
		for (int i = 1; i <= n; i++) {
			if (b[i] != c[i]) {
				yes = 0;
			}
		}
		std::cout << (yes?"YES\n":"NO\n");
	}
}