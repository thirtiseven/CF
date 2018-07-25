#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 1e5+7;

std::vector<int> t[maxn];
int nod[maxn], end[maxn], vis[maxn];
int ans = 0, cnt = 0;

void dfs(int node) {
	vis[node] = 1;
	cnt++;
	nod[node] = cnt;
	for (auto it : t[node]) {
		if (!vis[it]) dfs(it);
	}
	end[node] = cnt;
}

int main(int argc, char *argv[]) { 
	std::fill(vis, vis+maxn, 0); 
	int n;
	std::cin >> n;
	int u, v;
	for (int i = 1; i < n; i++) {
		std::cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	if (n%2==1) {
		std::cout << "-1\n";
		exit(0);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if ((end[i] - nod[i] + 1) % 2 == 0) {
			ans++;
		}
	}
	std::cout << ans-1 << '\n';
}