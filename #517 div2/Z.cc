#include <iostream>
#include <algorithm>
 
const int maxn = 22;

int g[maxn][3], vis[maxn], ans[maxn];
int m, cnt;
 
void dfs(int cur, int num) {
	if (num == 20) {
		bool flag = 0;
		for (int i=0; i<3; i++) {
			if (g[cur][i] == m) {
				flag = 1;
			}
		}
		if (flag) {
			std::cout << cnt << ": ";
			cnt++;
			for (int j=0; j<20; j++) {
				std::cout << " " << ans[j];
			}
			std::cout << " " << ans[0] << "\n";
		}
		return;
	}
	for (int i=0; i<3; i++) {
		if (!vis[g[cur][i]]) {
			ans[num] = g[cur][i];
			vis[g[cur][i]] = 1;
			dfs(g[cur][i], num+1);
			vis[g[cur][i]] = 0;
		}
	}
}
 
int main(int argc, char *argv[]) {
	for (int i = 1; i <= 20; i++) {
		std::cin >> g[i][0] >> g[i][1] >> g[i][2];
	}
	while (std::cin >> m) {
		if (!m) exit(0);
		cnt = 1;
		std::fill(vis, vis+maxn, 0);
		vis[m] = 1;
		ans[0] = m;
		dfs(m, 1);
	}
}

