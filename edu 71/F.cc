#include <iostream>
#include <algorithm>

const int maxn = 500043;
const int k = 750;

int res[k][k], a[maxn];

int main(int argc, char *argv[]) {  
	int q;
	std::cin >> q;
	while (q--) {
		int op, x, y;
		std::cin >> op >> x >> y;
		if (op == 1) {
			a[x] += y;
			for (int i = 1; i < k; i++) {
				res[i][x%i] += y;
			}
		} else {
			if (x >= k) {
				int ans = 0;
				for (int i = y; i <= 500000; i += x) {
					ans += a[i];
				}
				std::cout << ans << '\n';
			} else {
				std::cout << res[x][y] << '\n';
			}
		}
	}
}