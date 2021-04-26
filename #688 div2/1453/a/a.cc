#include <iostream>
#include <algorithm>
#include <set>

const int maxn = 123;

int T, n, m, a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::set<int> s;
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			s.insert(a[i]);
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			std::cin >> b[i];
			if (s.count(b[i])) {
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}