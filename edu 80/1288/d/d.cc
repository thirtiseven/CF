#include <iostream>
#include <climits>
#include <algorithm>

const int maxn = 3e5+7;

int a[maxn][11], b[300], c[300];
int n, m;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}
	for (int i = 0; i < (1<<m); i++) {
		b[i] = -1;
		for (int j = 1; j <= n; j++) {
			int x = INT_MAX;
			for (int k = 1; k <= m; k++) {
				if((i>>(k-1))&1) {
					x = std::min(x, a[j][k]);
				}
			}
			if (x > b[i]) {
				b[i] = x;
				c[i] = j;
			}
		}	
	}
	int ans = -1, ans1, ans2;
	for (int i = 0; i < (1<<m); i++) {
		if (std::min(b[i], b[((1<<m)-1)^i]) > ans) {
			ans = std::min(b[i], b[((1<<m)-1)^i]);
			ans1 = c[i];
			ans2 = c[((1<<m)-1)^i];
		}
	}
	std::cout << ans1 << ' ' << ans2 << '\n';
}