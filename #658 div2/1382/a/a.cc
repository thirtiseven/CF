#include <iostream>
#include <algorithm>
#include <set>

const int maxn = 1234;

int T, n, m, a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::set<int> aa;
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			aa.insert(a[i]);
		}
		int ans = -1;
		for (int i = 0; i < m; i++) {
			std::cin >> b[i];
			if (aa.count(b[i]) > 0) {
				ans = b[i];
			}
		}
		if (ans == -1) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n1 " << ans << '\n';
		}
	}
}