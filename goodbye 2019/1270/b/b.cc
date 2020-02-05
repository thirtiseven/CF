#include <iostream>
#include <algorithm>

using ll = long long;

const int maxn = 2e5+7;

int T, n, a[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int l = 0, r = 0;
		for (int i = 1; i < n; i++) {
			if (std::abs(a[i+1]-a[i]) >= 2) {
				l = i, r = i+1;
				break;
			}
		}
		if (l == 0) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n" << l << ' ' << r << '\n';
		}
	}
}