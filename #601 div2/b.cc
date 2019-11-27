#include <iostream>
#include <algorithm>
 
const int maxn = 1004;
 
int T, n, m;
std::pair<int, int> w[maxn];
 
int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> w[i].first;
			w[i].second = i;
			ans += w[i].first * 2;
		}
		if (m < n || n == 2) {
			std::cout << "-1\n";
			continue;
		}
		ans += (w[1].first + w[2].first) * (m-n);
		std::cout << ans << '\n';
		std::sort(w+1, w+n+1);
		for (int i = 1; i < n; i++) {
			std::cout << w[i].second << ' ' << w[i+1].second << '\n';
		}
		std::cout << w[n].second << ' ' << w[1].second << '\n';
		for (int i = n+1; i <= m; i++) {
			std::cout << w[1].second << ' ' << w[2].second << '\n';
		}
	}
}