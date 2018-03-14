#include <iostream>

char r[2009][2009];

int main(int argc, char *argv[]) {  
	int n, m, k;
	std::cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> r[i];
	}
	if (k == 1) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (r[i][j] == '.') {
					ans++;
				}	
			}
		}
		std::cout << ans << '\n';
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tot = 0;
		for (int j = 0; j < m; j++) {
//			std::cout << r[i][j];
			if (r[i][j] == '*') {
				if (tot >= k) {
					ans += (tot-k+1);
				} 
				tot = 0;
			}
			if (r[i][j] == '.') {
				tot++;
			}
		}
		if (tot >= k) {
			ans += (tot-k+1);
		} 
		tot = 0;
	}
	for (int i = 0; i < m; i++) {
		int tot = 0;
		for (int j = 0; j < n; j++) {
//			std::cout << r[j][i];
			if (r[j][i] == '*') {
				if (tot >= k) {
					ans += (tot-k+1);
				} 
				tot = 0;
			}
			if (r[j][i] == '.') {
				tot++;
			}
		}
		if (tot >= k) {
			ans += (tot-k+1);
		} 
		tot = 0;
	}
	std::cout << ans;
}