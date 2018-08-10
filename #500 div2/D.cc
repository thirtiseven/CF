#include <iostream>
#include <algorithm>
#include <set>

const int maxn = 2e5+7;

int fa[maxn*2];

void init(int n) {
	for (int i = 1; i <= n; i++) fa[i] = i;
}

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
	fa[find(v)] = find(u);
}

int main(int argc, char *argv[]) {  
	int n, m, q, x, y;
	std::cin >> n >> m >> q;
	init(n+m);
	int ans = n+m-1;
	for (int i = 0; i < q; i++) {
		std::cin >> x >> y;
		y += n;
		if (find(x)!=find(y)) {
			ans--;
			unin(x, y);
		}
	}
	std::cout << ans;
}