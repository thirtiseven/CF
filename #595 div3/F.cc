#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 211;

int n, m, k;		
std::vector<int> t[maxn];
int a[maxn];
int g[maxn][maxn];	//0-labeled
int linker[maxn];
bool used[maxn];

bool dfs(int u) {
	int v;
	for(v = 0; v < m; v++) {
		if(g[u][v] && !used[v]) {
			used[v] = true;
			if(linker[v] == -1 || dfs(linker[v])) {
				linker[v] = u;
				return true;
			}    
		} 
	}
	return false;  
}   
 
int hungary() {
	int res = 0;
	int u;
	memset(linker, -1, sizeof(linker)); 
	for(u = 0; u < n; u++) {
		memset(used, 0, sizeof(used));
		if(dfs(u)) {
			res++;
		}
	} 
	return res;   
} 

int vis[maxn];

void lab(int now, int fa, int dis) {
	if (dis <= k) {
		vis[now] = 1;
		for (auto it: t[now]) {
			if (it != fa) {
				lab(it, now, dis+1);
			}
		}
	}
	return;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int u, v;
	for (int i = 0; i < n-1; i++) {
		std::cin >> u >> v;
		t[u-1].push_back(v-1);
		t[v-1].push_back(u-1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		std::fill(vis, vis+maxn, 0);
		lab(i, -1, 0);
		for (int j = 0; j < n; j++) {
			if (i != j && !vis[j]) {
				g[i][j] = a[i]+a[j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << g[i][j] << ' ';
		}
		std::cout << '\n';
	}
	int ans = hungary();
	ans /= 2;
	std::cout << ans << '\n';
}