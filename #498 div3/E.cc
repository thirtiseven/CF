#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

const int maxn = 2e5+7;
int n, q, t;
std::vector<int> p[maxn];
int end[maxn];
int cnt = 0;
int nod[maxn];
int ans[maxn];

void dfs(int node) {
	cnt++;
	nod[node] = cnt;
	ans[cnt] = node;
	for (auto it : p[node]) {
		dfs(it);
	}
	end[node] = cnt;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		std::cin >> t;
		p[t].push_back(i);
	}
	dfs(1);
//	for (int i = 1; i <= n; i++) {
//		std::cout << i << " " << end[i] << '\n';
//	}
	int a, b;
	for (int i = 0; i < q; i++) {
		std::cin >> a >> b;
		if (nod[a]+b-1 > end[a] || nod[a]+b-1 > n) {
			std::cout << "-1\n";
		} else {
			std::cout << ans[nod[a]+b-1] << '\n';
		}
	}
}