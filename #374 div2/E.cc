#include <algorithm>
#include <iostream>

#define maxn 100010

int main(int argc, char *argv[]) {
	int f[maxn], g[maxn], l, n, p, t;
	std::cin >> l >> n >> p >> t;
	g[0] = -t;
	for (int i = 1, j = 1; i <= n; i++) {
		int l, r;
		std::cin >> l >> r;
		g[i] = g[i - 1];
		f[i] = f[i - 1];
		for (j--; j < i && g[j] + t <= r;j++) {
			int x = std::max(g[j] + t, l);
			int y = f[j] + (r - x) / p;
			int z = r - (r - x) % p;
			if (y > f[i] || (y == f[i] && z < g[i])) {
				f[i] = y, g[i] = z;
			}
		}
	}
	std::cout << f[n];
	return 0;
}