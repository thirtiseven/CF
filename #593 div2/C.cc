#include <iostream>

int ans[303][303];

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int now = 1;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				ans[j][i] = now;
				now++;
			}
		} else {
			for (int j = n; j >= 1; j--) {
				ans[j][i] = now;
				now++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << ans[i][j] << ' ';
		}
		std::cout << '\n';
	}
}