#include <iostream>
#include <cstring>

const int maxn = 100003;

int fa[maxn];
int vis[maxn];
int in[maxn];

void init(int n) {
	for (int i = 1; i <= n; i++) fa[i] = i;
	memset(vis, 0, sizeof(vis));
	memset(in, 0, sizeof(in));
}

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
	fa[find(v)] = find(u);
}

int main(int argc, char *argv[]) {  
	int u, v;
	init(100000);
	int casss = 1;
	bool ok = 1;
	while (std::cin >> u >> v) {
		if (u < 0 || v < 0) {
			return 0;
		}
		if (u == 0 && v == 0) {
			int cnt = 0;
			for (int i = 1; i <= 100000; i++) {
				if (vis[i] && find(i) == i) {
					cnt++;
				}
			}
			for (int i = 1; i <= 100000; i++) {
				if (in[i] > 1) {
					ok = 0;
				}
			}
			if (cnt > 1 || !ok) {
				std::cout << "Case " << casss << " is not a tree.\n";
				casss++;
			} else {
				std::cout << "Case " << casss << " is a tree.\n";
				casss++;
			}
			init(100000);
			ok = 1;
			continue;
		}
		vis[u] = 1;
		vis[v] = 1;
		in[v]++;
		if (find(u) == find(v)) ok = 0;
		unin(u, v);
	}
}