#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

#define maxn 100000
std::vector<int> t[maxn];
int n;
long double ans;
bool vis[maxn];

void dfs(int node, int deep, long double now) {
	if(vis[node]) {
		return;
	}
	vis[node] = 1;
	long double size;
	if(node == 1) {
		size = (long double)(t[node].size());
	} else {
		size = (long double)(t[node].size()) - 1;
	}
	int cnt = 0;
	for(std::vector<int>::iterator it = t[node].begin(); it != t[node].end(); it++) {
		if(!vis[*it]) {
			dfs(*it, deep+1, now/size);
			cnt++;
		}
	}
	if(cnt == 0) {
		ans += deep * now;
		//std::cout << node << " " << deep << " " << now << " " << std::fixed << std::setprecision(8) << ans << std::endl;
	}
}

int main(int argc, char *argv[]) {  
	std::cin >> n;
	int u, v;
	for(int i = 0; i < n - 1; i++) {
		std::cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	ans = 0;
	memset(vis, 0, sizeof(vis));
	dfs(1, 0, 1.0);
	std::cout << std::fixed << std::setprecision(8) << ans << std::endl;
	return 0;
}