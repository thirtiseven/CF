#include <iostream>
#include <algorithm>

const int inf = 10000009;
const int maxn = 1009;
int d[maxn][maxn];

int main(int argc, char *argv[]) {  
	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j < maxn; j++) {
			d[i][j] = inf;
		}
	}
	int n, m, s, t;
	std::cin >> n >> m >> s >> t;
	s--, t--;
	int tempn, tempm;
	for (int i = 0; i < m; i++) {
		std::cin >> tempn >> tempm;
		d[tempn-1][tempm-1] = 1;
		d[tempm-1][tempn-1] = 1;
	}
	d[0][0] = 0;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);		
			}
		}
	}
	for (int i = 0; i < n; i++) {
		d[i][i] = 0;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[s][t] <= d[s][i] + d[j][t] + 1 && d[s][t] <= d[s][j] + d[i][t] + 1 && i != j && d[i][j] > 1) {
//				std::cout << i << " " << j << '\n';
//				std::cout << d[i][j] << '\n';
//				std::cout << d[s][t] << " " << d[i][j] << " " << d[s][i] << " " << d[j][t] << '\n';
				ans++;
			}
		}
	}
//	std::cout << ans << '\n';
	if (ans)
		std::cout << ans/2;
	else {
		std::cout << 0;
	}
}