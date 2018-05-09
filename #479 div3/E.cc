#include <iostream>
#include <vector>
#include <cstring>

const int maxn = 2e5;
std::vector<int> p[maxn];
int vis[maxn];
int ans;
int n, m, u, v;

void dfs(int v, int s, int flag, int pre) {
//	std::cout << v << " " << s << '\n';
	if(vis[v] && v == s && flag != 0 && pre != v) {
		ans ++;
		return;
	}
	if (vis[v]) {
		return;
	}
	vis[v] = 1;
	if (p[v].size() == 2) {
		dfs(p[v][0], s, flag+1, v);
		dfs(p[v][1], s, flag+1, v);
	}
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		dfs(i, i, 0, 0);
	}
	std::cout << ans/2;
}