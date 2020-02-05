#include <iostream>
#include <map>
#include <vector>

using ll = long long;

const int maxn = 1e3+6;

ll g[maxn][maxn], dis[maxn][maxn];
int n;
std::pair<ll, ll> p[maxn];

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
	std::cin >> n;
	init(n);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i].first >> p[i].second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = (p[i].first - p[j].first)*(p[i].first - p[j].first)+(p[i].second - p[j].second)*(p[i].second - p[j].second);
			g[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		std::map<ll, std::vector<int>> mp;
		for (int j = 1; j <= n; j++) {
			mp[dis[i][j]].push_back(j);
		}
		for (auto it: mp) {
			int len = it.second.size();
			for (int j = 1; j < len; j++) {
				unin(it.second[0], it.second[j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		std::cout << find(i) << ' ';
	}
	std::cout << '\n';
	std::vector<int> ans;
	int x = 1;
	for (int i = 1; i <= n; i++) {
		if (find(i) == find(x)) {
			ans.push_back(i);
		}
	}
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << it << ' ';
	}
	std::cout << '\n';
}


Legendary grandmaster
ecnerwala