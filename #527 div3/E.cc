#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 1234;

int n, m;
int a[maxn];
bool vis[maxn];
std::vector<int> g[maxn];
std::pair<int, int> dia[maxn];

bool cmp(std::pair<int, int> a, std::pair<int, int> b){
	return a.first > b.first;
}

int gras[maxn];
int tree_cnt = 0;
int vMax[maxn];

void dfs(int u) {
	vis[u] = 1;
	for (auto v: g[u]) {
		if (!vis[v]) {
			dfs(v);
			if (vMax[u] + vMax[v] + 1 > dia[tree_cnt].first) {
				dia[tree_cnt].first = vMax[u] + vMax[v] + 1;
				dia[tree_cnt].second = u;
			}
			if (vMax[v] + 1 > vMax[u]) {
				vMax[u] = vMax[v] + 1;
				gras[u] = v;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int u, v;
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			tree_cnt++;
			dia[tree_cnt].first=0;
			dia[tree_cnt].second=i;
			dfs(i);
		}
	}
	std::sort(dia + 1, dia + tree_cnt + 1, cmp);
	int Maxv = 1, Maxdia = dia[1].first;
	for (int i = 1; i <= tree_cnt; i++){
		int val = vMax[dia[i].second];
		for (int j = val; j > (dia[i].first+1)/2; j--) {
			dia[i].second = gras[dia[i].second];
		}
		if (Maxv == i) {
			continue;
		}
		if (Maxdia == 1 && dia[i].first == 1) {
			Maxdia += 2;
		} else if (std::abs(dia[i].first - Maxdia) <= 1) {
			Maxdia +=1;
		} else if (std::abs(dia[i].first - Maxdia)==2 && (dia[i].first&1) && (Maxdia&1)) {
			Maxdia++;
		}
	}
	std::cout << Maxdia << '\n';
	for (int i = 2; i <= tree_cnt; i++) {
		std::cout << dia[Maxv].second << " " << dia[i].second << '\n';
	}
}