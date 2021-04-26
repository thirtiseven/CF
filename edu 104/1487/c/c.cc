#include <iostream>
#include <algorithm>

const int maxn = 123;

int t, n, g[maxn][maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n/2; j++) {
				g[i][(i+j)%n] = 1;
				g[(i+j)%n][i] = -1;
			}
			if (n % 2 == 0) {
				g[i][(i+n/2)%n] = 0;
				g[(i+n/2)%n][i] = 0;
			}
		}
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				std::cout << g[i][j] << ' ';
			}
		}
		std::cout << '\n';
	}
}