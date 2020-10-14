#include <iostream>
#include <algorithm>

const int maxn = 321;

int t, n, m, a[maxn][maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		bool yes = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cin >> a[i][j];
				if ((i == 0 || i == n-1) && (j == 0 || j == m-1)) {
					if (a[i][j] > 2) {
						yes = 0;
					} else {
						a[i][j] = 2;
					}
				} else if (i == 0 || i == n-1 || j == 0 || j == m-1) {
					if (a[i][j] > 3) {
						yes = 0;
					} else {
						a[i][j] = 3;
					}
				} else {
					if (a[i][j] > 4) {
						yes = 0;
					} else {
						a[i][j] = 4;
					}
				}
			}
		}
		if (yes) {
			std::cout << "YES\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					std::cout << a[i][j] << ' ';
				}
				std::cout << '\n';
			}
		} else {
			std::cout << "NO\n";
		}
//		std::cout << "--------\n";
	}
}