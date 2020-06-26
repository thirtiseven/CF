#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 1007;

int T, n, m, x, y;
std::string s[maxn];  

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m >> x >> y;
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '.' && j < m-1 && s[i][j+1] == '.' && 2*x>y) {
					ans += y;
					j++;
				} else if (s[i][j] == '.') {
					ans += x;
				}
			}
		}
		std::cout << ans << '\n';
	}
}