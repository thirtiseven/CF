#include <iostream>

const int mod = 1e9+7;
const int maxn = 1e3+7;

int m[maxn][maxn];
int w, h, r[maxn], c[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> h >> w;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			m[i][j] = 0;
		}
	}
	
	for (int i = 0; i < h; i++) {
		std::cin >> r[i];
		for (int j = 0; j < r[i]; j++) {
			m[i][j] = 1;
		}
		m[i][r[i]] = 2;
	}
	
	bool yes = 1;
	
	for (int i = 0; i < w; i++) {
		std::cin >> c[i];
		for (int j = 0; j < c[i]; j++) {
			if (m[j][i] == 2) {
//				std::cerr << i << ' ' << j << '\n';
				yes = 0;
			}
			m[j][i] = 1;
		}
		if (m[c[i]][i] == 1) {
//			std::cerr << c[i]+1 << ' ' << i << '\n';
			yes = 0;
		}
		m[c[i]][i] = 2;
	}
	
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			std::cout << m[i][j] << ' ';
//		}
//		std::cout << '\n';
//	}
	
	if (yes == 0) {
		std::cout << "0\n";
		exit(0);
	}
	
	int tot = 0;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (m[i][j] == 0) {
				tot++;
			}
		}
	}
	
	int ans = 1;
	for (int i = 0; i < tot; i++) {
		ans *= 2;
		ans %= mod;
	}
	
	std::cout << ans << '\n';
}
