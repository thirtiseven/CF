#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 321;

int T, n, k;
char ans[maxn][maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans[i][j] = '0';
			}
		}
		int x = 0, y = 0;
		for (int i = 0; i < k; i++) {
			ans[x][(x+y)%n] = '1';
			if (x == n-1) {
				x = 0;
				y ++;
			} else {
				x++;
			}
		}
		if (k%n==0) {
			std::cout << "0\n";
		} else {
			std::cout << "2\n";
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << ans[i][j];
			}
			std::cout << '\n';
		}
	}
}