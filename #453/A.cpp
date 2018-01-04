#include <iostream>

#define inf 10000000

int main(int argc, char *argv[]) {  
	int n, m, x, y;
	int d[109][109];
	std::cin >> n >> m;
	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= m; j++) {
			d[i][j] = inf;
		}
	}
	for(int i = 0; i < n; i++) {
		std::cin >> x >> y;
		for(int j = x; j <=y; j++) {
			d[x][j] = 1;
		}
	}
	d[0][0] = 0;
	for(int k = 0; k <= m; k++) {
		for(int i = 0; i <= m; i++) {
			for(int j = 0; j <=m; j++) {
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);		
			}
		}
	}
	if(d[0][m] < inf) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
	return 0;
}