#include <iostream>
#include <algorithm>

const int maxn = 2e5+6;

int T, n, e[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> e[i];
		}
		std::sort(e, e+n);
		int ans = 0, num = 0;
		for (int i = 0; i < n; i++) {
			num++;
			if (num >= e[i]) {
				ans++;
				num=0;
			}
		}
		std::cout << ans << '\n';
	}
}