#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int t, n, a[maxn];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int min_cnt = INT_MAX, even = 0;
		for (int i = 0; i < n; i++) {
			int temp = a[i];
			int cnt = 0;
			if (temp % 2 == 0) {
				even++;
			}
			while (temp % 2 == 0) {
				cnt++;
				temp /= 2;
			}
			min_cnt = std::min(min_cnt, cnt);
		}
		if (min_cnt == 0) {
			std::cout << even << '\n';
		} else {
			std::cout << n - 1 + min_cnt << '\n';
		}
	}
	
	
}