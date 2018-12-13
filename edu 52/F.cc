#include <iostream>
#include <vector>

const int maxn = 1e6;

std::vector<int> t[maxn];
int dep[maxn];

int dfs(int cur, int fa) {
	int ans = maxn*2;
	if (t[cur].size()==1) {
		return dep[cur] = 1;
	}
	for (auto it: t[cur]) {
		if (it != fa) {
			ans = std::max(it, cur);
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {  
	int n, k, tt;
	std::cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		std::cin >> tt;
		t[tt].push_back(i);
		t[i].push_back(tt);
	}
	dep[1] = dfs(1, 0);
	int aa = 0;
	for (int i = 1; i <= n; i++) {
		if (dep[i] <= k) {
			aa++;
		}
	}
	std::cout << aa;
}