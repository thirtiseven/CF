#include <iostream>
#include <algorithm>

const int maxn = 2e5+8;

int t, n;
int vis[maxn];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		std::fill(vis, vis+n+1, 0);
		std::cout << "2\n";
		int x = 1, mex = 1;
		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				std::cout << vis[j] << " \n"[j==n];
//			}
//			std::cout << x << ' ' << mex << '\n';
			if (x > n) {
				while (vis[mex]) {
					mex++;
				}
				x = mex;
			}
			vis[x] = 1;
			std::cout << x << ' ';
			x *= 2;
		}
		std::cout << '\n';
	}
}