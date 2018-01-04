#include <iostream>
#include <vector>
#include <cstring>

const int maxn = 3e4 + 10;

int n, t, a[maxn];
std::vector<int> g[maxn];
bool vis[maxn];
bool flag;

void dfs(int m) {
	vis[m] = 1;
	if(m == t) {
		flag = 1;
	}
	for(auto it: g[m]) {
		if(!vis[it]) {
			dfs(it);
		}
	}
	return;
}

int main(int argc, char *argv[]) {  
	memset(vis, 0, sizeof(vis));
	flag = 0;
	std::cin >> n >> t;
	for (int i = 1; i < n; i++) {
		std::cin >> a[i];
		g[i].push_back(i+a[i]);
	}
	dfs(1);
	std::cout << (flag?"YES\n":"NO\n");
	return 0;
}