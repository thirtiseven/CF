#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 1e5+6;

std::vector<std::pair<int, int>> edge;
std::vector<int> g[maxn];
int col[maxn], cnt[maxn];
int n, m, u, v;

int main(int argc, char *argv[]) {  
	std::fill(col, col+maxn, 0);
	std::fill(cnt, cnt+maxn, 0);
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		edge.push_back(std::make_pair(u, v));
	}
	col[1] = 1;
	for (auto it: g[1]) {
		col[it] = 2;
	}
	if (g[1].size() == 0) {
		std::cout << "-1\n";
		exit(0);
	}
	int x = g[1][0];
	for (auto it: g[x]) {
		if (col[it] == 2) {
			col[it] = 3;
		} else {
			col[it] = 1;
		}
	}
	bool yes = 1;
	for (int i = 1; i <= n; i++) {
		for (auto it: g[i]) {
			if (col[it] == col[i]) {
				yes = 0;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (col[i] == 0) {
			yes = 0;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt[col[i]]++;
	}
	if (!cnt[3] || !cnt[2]) {
		yes = 0;
	}
	int onetwo = 0, twothree = 0, threeone = 0;
	for (auto it: edge) {
		if ((col[it.first] == 1 && col[it.second] == 2) || (col[it.first] == 2 && col[it.second] == 1)) {
			onetwo++;
		} else if ((col[it.first] == 3 && col[it.second] == 2) || (col[it.first] == 2 && col[it.second] == 3)) {
			twothree++;
		} else if ((col[it.first] == 1 && col[it.second] == 3) || (col[it.first] == 3 && col[it.second] == 1)) {
			threeone++;
		}
	}
	if (onetwo != cnt[1]*cnt[2]) {
		yes = 0;
	}
	if (twothree != cnt[2]*cnt[3]) {
		yes = 0;
	}
	if (threeone != cnt[3]*cnt[1]) {
		yes = 0;
	}
	if (yes) {
		for (int i = 1; i <= n; i++) {
			std::cout << col[i] << ' ';
		}
	} else {
		std::cout << "-1\n";
	}
}