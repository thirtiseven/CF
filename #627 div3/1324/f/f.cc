#include <iostream>
#include <vector>

const int maxn = 2e5+8;

int n, u, v, d;
std::vector<int> t[maxn];
int c[maxn];
int l, x[maxn];

int dfs(int now, int fa) {
	if (t[now].size() == 1) {
		if (c[now] == 0) {
			x[i] = 1;
			return 1;	
		}
		x[i] = -1;
		return -1;
	}
	
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	l = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
		d += (c[i]==1?1:-1);
	}
	for (int i = 0; i < n-1; i++) {
		std::cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
}