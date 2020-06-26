#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 2e5+7;
const int maxa = 231;

int t, n, a[maxn];
std::vector<int> pos[maxa];
int pre[maxa][maxn];

void init() {
	for (int i = 1; i <= 200; i++) {
		pos[i].clear();
		pre[i][0] = 0;
	}
}

int maxnum(int l, int r) {
	int res = 0;
	for (int i = 1; i <= 200; i++) {
		res = std::max(res, pre[i][r]-pre[i][l-1]);
	}
	return res;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		init();
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			pos[a[i]].push_back(i);
			for (int j = 1; j <= 200; j++) {
				pre[j][i] = pre[j][i-1];
			}
			pre[a[i]][i]++;
		}
		int ans = maxnum(1, n);
		for (int i = 1; i <= 200; i++) {
			if (pos[i].empty()) continue;
			int x = 0, y = pos[i].size()-1;
			while (pos[i][x] < pos[i][y]) {
//				std::cout << pos[i][x] <<' ' <<  pos[i][y] << '\n';
				ans = std::max(ans, (x+1)*2+maxnum(pos[i][x]+1, pos[i][y]-1));
				x++, y--;
			}
		}
		std::cout << ans << '\n';
	}
}