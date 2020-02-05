#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int n, a[maxn];

int vis[maxn], ans[maxn];

int dfs(int cur, int fa) {
	if (vis[cur]) {
		return ans[cur];
	}
	if (fa != 0 && a[cur] % 2 != a[fa] % 2) {
		ans[fa] = 1;
	}
	vis[cur] = 1;
	if (1 <= cur-a[cur]) {
		ans[cur] = std::min(ans[cur], dfs(cur-a[cur], cur)+1);
	}
	if (cur+a[cur] <= n) {
		ans[cur] = std::min(ans[cur], dfs(cur+a[cur], cur)+1);
	}
	return ans[cur];
}

int main(int argc, char *argv[]) {  
	std::fill(vis, vis+maxn, 0);
	std::fill(vis, vis+maxn, -1);
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 0);
	}
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << ' ';
	}
}