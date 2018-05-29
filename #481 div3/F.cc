#include <iostream>
#include <algorithm>

const int maxn = 2e5+9;

int main(int argc, char *argv[]) {  
	int n, r[maxn], s[maxn], ans[maxn], k, a, b;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> r[i];
		s[i] = r[i];
	}
	std::sort(s+1, s+1+n);
	for (int i = 1; i <= n; i++) {
		ans[i] = std::lower_bound(s+1, s+1+n, r[i]) - (s+1);
	}
	for (int i = 0; i < k; i++) {
		std::cin >> a >> b;
		if (r[a] < r[b]) {
			ans[b]--;
		} else if (r[a] > r[b]) {
			ans[a]--;
		}
	}
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << " ";
	}
}