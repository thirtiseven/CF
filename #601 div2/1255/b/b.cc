#include <iostream>
#include <algorithm>
#include <cassert>

const int maxn = 1004;

int T, n, m;
std::pair<int, int> w[maxn];
int in[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> w[i].first;
			w[i].second = i;
		}
		if (m < n || n == 2) {
			std::cout << "-1\n";
			continue;
		}
		std::sort(w+1, w+n+1);
		for (int i = 2; i <= n; i++) {
			in[w[i].second] = 2;
		}
		in[w[1].second] = std::min(2*m-2*(n-1), ((n-1)%2==0?n-1:n-2));
		int cur = 2*m-2*(n-1)-in[w[1].second];
		in[w[2].second] += cur/2;
		in[w[1].second] += cur/2;
		assert(cur % 2 == 0);
		for (int i = 1; i <= n; i++) {
			ans += in[w[i].second] * w[i].first;
		}
		std::cout << ans << '\n';
		for (int i = 0; i < m; i++) {
			int x = 1, y = n;
			while (in[w[x].second] == 0) {
				x++;
			}
			while (in[w[y].second] == 0) {
				y--;
			}
			std::cout << w[x].second << ' ' << w[y].second << '\n';
			in[w[x].second]--;
			in[w[y].second]--;
		}
	}
}