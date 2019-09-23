#include <iostream>

const int maxn = 1e5+7;

int fa[maxn];

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
	int n, k, u, v;
	std::cin >> n >> k;
	init(n);
	int ans = 0;
	for (int i = 0; i < k; i++) {
		std::cin >> u >> v;
		if (find(u) != find(v)) {
			ans++;
			unin(u, v);
		}
	}
	std::cout << k-ans << '\n';
}