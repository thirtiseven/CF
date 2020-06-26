#include <iostream>
#include <algorithm>

const int maxn = 223;

int t, n, x, a[maxn], num[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> x;
		std::fill(num, num+maxn, 0);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			num[a[i]] = 1;
		}
		std::sort(a, a+n);
		int ans = 1;
		while (ans <= 200) {
			if (num[ans]) {
				ans++;
			} else if (x > 0) {
				x--;
				ans++;
			} else {
				break;
			}
		}
		std::cout << ans-1 << '\n';
	}
}