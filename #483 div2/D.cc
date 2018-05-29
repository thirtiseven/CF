#include <iostream>
#include <algorithm>

const int maxn = 5009;
int b[maxn];
int q[maxn][maxn];
int n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		q[i][1] = b[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n-i+1; j++) {
			q[j][i] = q[j][i-1] ^ q[j+1][i-1];
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n-i+1; j++) {
			q[j][i] = std::max(q[j][i], std::max(q[j][i-1], q[j+1][i-1]));
		}
	}
	int T;
	std::cin >> T;
	while (T--) {
		int l, r;
		std::cin >> l >> r;
		std::cout << q[l][r-l+1] << '\n';
	}
}