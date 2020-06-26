#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 200000+7;

int t, n, a[maxn], num[maxn], check1[maxn], check2[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		std::fill(num, num+n+1, 0);
		std::fill(check1, check1+n+1, 0);
		std::fill(check2, check2+n+1, 0);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			maxx = std::max(maxx, a[i]);
			if (num[a[i]]) {
				break;
 			}
			if (maxx == i) {
				check1[i] = 1;
			}
			num[a[i]] = 1;
		}
		std::fill(num, num+n+1, 0);
		maxx = 0;
		for (int i = n; i >= 1; i--) {
			maxx = std::max(maxx, a[i]);
			if (num[a[i]]) {
				break;
 			}
			if (maxx == n-i+1) {
				check2[i] = 1;
			}
			num[a[i]] = 1;
		}
		std::vector<std::pair<int, int>> ans;
		for (int i = 1; i < n; i++) {
			if (check1[i] && check2[i+1]) {
				ans.push_back(std::make_pair(i, n-i));
			}
		}
		std::cout << ans.size() << '\n';
		for (auto it: ans) {
			std::cout << it.first << ' ' << it.second << '\n';
		}
	}
}