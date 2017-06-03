#include <iostream>
#include <vector>
#include <cstring>

#define maxn 200010
#define inf 1e9

typedef long long ll;

std::vector<ll> tree[maxn];
int vis[maxn];
ll sum[maxn];
int pleasantness[maxn];

int dfs(int v, int fa) {
	if(vis[v]) {
		return 0;
	}
	vis[v] = 1;
	ll sum_temp = pleasantness[v];
	ll son_max = -inf;
	int flag = 1;
	for(int i = 0; i <= tree[v].size(); i++) {
		if(i == tree[v].size()&&flag) {
			son_max = 0;
			break;
		}
		if(tree[v][i] != fa) {
			ll temp = dfs(tree[v][i], v);
			if(temp > son_max) {
				son_max = temp;
				flag = 0;
			}
		}
	}
	sum_temp += son_max;
	sum[v] = sum_temp;
	return sum_temp;
}

int main(int argc, char *argv[]) {  
	memset(vis, 0, sizeof(vis));
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> pleasantness[i];
	}
	for(int i = 0; i < n-1; i++) {
		int a, b;
		std::cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, -1);
	for(int i = 1; i <= n; i++) {
		std::cout << sum[i] << " ";
	}
	return 0;
}