#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 200000+8;

int fa[maxn], n, m;
int maxx[maxn], minn[maxn];

void init(int x) {
	for (int i = 1; i <= x; i++) fa[i] = i;
}

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
	fa[find(v)] = find(u);
}

std::vector<std::pair<int, int>> seg;

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	init(n);
	int u, v;
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v;
		unin(u, v);
	}
	std::fill(maxx, maxx+maxn, 0);
	std::fill(minn, minn+maxn, 100000000);
	int x;
	for (int i = 1; i <= n; i++) {
		x = find(i);
		maxx[x] = std::max(i, maxx[x]);
		minn[x] = std::min(i, minn[x]);
	}
	for (int i = 1; i <= n; i++) {
		if (minn[i] != 100000000) {
			seg.push_back(std::make_pair(minn[i], maxx[i]));
		}
	}
	std::sort(seg.begin(), seg.end());
	int ans = 0;
	int now = 0;
	for (int i = 0; i < seg.size(); i++) {
//		std::cout << seg[i].first << ' ' << seg[i].second << '\n';
		if (now > seg[i].first) {
			ans++;
		}
		now = std::max(seg[i].second, now);
	}
	std::cout << ans << '\n';
}