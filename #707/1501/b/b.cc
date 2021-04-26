#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
int t, n, a[maxn], ans[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			ans[i] = 0;
		}
		for (int i = n; i >= 1; i--) {
			if (a[i] > 0) {
				a[i-1] = std::max(a[i-1], a[i]-1);
			}
		}
		for (int i = 1; i <= n; i++) {
			std::cout << int(a[i] > 0) << ' ';
		}
		std::cout << '\n';
	}
}