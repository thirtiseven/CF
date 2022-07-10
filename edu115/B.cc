#include <iostream>
#include <algorithm>

int t, n;
int ok[1024][6];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				std::cin >> ok[i][j];
			}
		}
		bool yes = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = i+1; j < 5; j++) {
				int tf = 0, ft = 0, tt = 0, ff = 0;
				for (int k = 0; k < n; k++) {
					if (ok[k][i] == 0 && ok[k][j] == 0) {
						ff = 1;
						break;
					} else if (ok[k][i] == 1 && ok[k][j] == 0) {
						tf++;
					} else if (ok[k][i] == 0 && ok[k][j] == 1) {
						ft++;
					} else {
						tt++;
					}
				}
				if (ff == 0) {
					if (tf <= n / 2 && ft <= n / 2) {
						yes = 1;
						goto out;
					}
				}
			}
		}
		out:;
		if (yes) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}