#include <iostream>
#include <vector>
#include <algorithm>  
#include <queue>

const int maxn = 1e5+7;
int n, m;
std::vector<int> g[maxn];
std::priority_queue<int, std::vector<int>, std::greater<int>> now;
int vis[maxn], add[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);   
	}
	std::fill(vis, vis+maxn, 0);
	std::fill(add, add+maxn, 0);
	now.push(1);
	while (!now.empty()) {
		int xx = now.top();
		now.pop();
		if (!vis[xx]) std::cout << xx << ' ';
		vis[xx] = 1;
		for (auto it: g[xx]) {
			if (!vis[it] && !add[it]) {
				add[it] = 1;
				now.push(it);
			}
		}
	}
}