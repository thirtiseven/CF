#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 1e5+7;
std::vector<int> t[maxn];
int n, u, v;
int depth[maxn];

void gao(int now, int fa, int dep) {
	depth[now] = dep;
	for (auto it: t[now]) {
		if (it != fa) {
			gao(it, now, dep+1);
		}
	}
}

int dfs(int now, int fa) {
	if (t[now].size() == 1) {
		return 1;
	}
	bool one = 0;
	int res = 0, x = 0;
	for (auto it: t[now]) {
		if (it != fa) {
			x = dfs(it, now);
			if (x == 1) {
				if (one == 0) {
					res++;
					one = 1;					
				}
			} else {
				res += x;
			}
		}
	}
	return res+1;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	std::fill(depth, depth+n+1, 0);
	for (int i = 0; i < n-1; i++) {
		std::cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	int start = -1;
	for (int i = 1; i <= n; i++) {
		if (t[i].size() > 1) {
			start = i;
			break;
		}
	}
	gao(1, 0, 0);
	int odd = 0, even = 0;
	for (int i = 1; i <= n; i++) {
		if (t[i].size() == 1) {
			if (depth[i]%2==0) {
				even++;
			} else {
				odd++;
			}
		}
	}
//	std::cout << start << "\n";
	if (even ==0 || odd == 0) {
		std::cout << 1 << ' ';
	} else {
		std::cout << "3 ";
	}
	std::cout << dfs(start, 0)-1 << '\n';
}