#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;
const int maxn = 1024;

int T, n;
ll c[maxn][maxn], col[maxn], row[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			col[i] = 0;
			row[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cin >> c[i][j];
				if (i < j) {
					col[j-i] += c[i][j];
				} else {
					row[i-j] += c[i][j];
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans = std::max(ans, col[i]);
			ans = std::max(ans, row[i]);
		}
		std::cout << "Case #" << CAS << ": " << ans << '\n';
	}
}