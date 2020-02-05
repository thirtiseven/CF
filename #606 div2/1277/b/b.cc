#include <iostream>
#include <map>
#include <vector>

int T, n, a;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::map<int, int> vis;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a;
			if (a % 2 == 0) {
				vis[a] = 1;
			}
		}
		int ans = 0, x;
		for (auto it = vis.rbegin(); it != vis.rend(); it++) {
			if (vis[(*it).first] == 0) continue;
			x = (*it).first;
			while (x % 2 == 0) {
				vis[x] = 0;
				x /= 2;
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}