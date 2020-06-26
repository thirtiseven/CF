#include <iostream>
#include <map>
#include <algorithm>

const int maxn = 2e5+7;

int t, n, a[maxn];
std::map<int, int> num;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		num.clear();
		int x, y;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			num[a[i]]++;
		}
		x = num.size(), y = 0;
		for (auto it: num) {
			y = std::max(y, it.second);
		}
		int ans = n/2;
		if (y-1 < x) {
			x--;
		}
		ans = std::min(x, ans);
		ans = std::min(y, ans);
		std::cout << ans << '\n';
	}
}