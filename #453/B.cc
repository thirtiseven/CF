#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

const int maxn = 1e4+9;
std::vector<int> g[maxn];
int anss;
int n;
int t;
int c[maxn];
int vis[maxn];

void dfs(int root, int fa) {
	vis[root] = 1;
	anss++;
	if(c[root] == c[fa]) {
//		std::cout << root << " " << fa << '\n';
		anss--;
	}
	for(auto it: g[root]) {
		if(!vis[it]) {
			dfs(it, root);
		}
	}
}

int main(int argc, char *argv[]) {  
	std::cin >> n;
	memset(vis, 0, sizeof(vis));
	anss = 1;
	for(int i = 2; i <= n; i++) {
		std::cin >> t;
		g[i].push_back(t);
		g[t].push_back(i);
//		std::cout << t << " " << i << '\n';

	}
	for(int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}
	c[0] = c[1];
	dfs(1, 0);
	std::cout << anss;
	return 0;
}