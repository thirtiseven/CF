#include <iostream>
#include <algorithm>

const int maxn = 123;

int T;
int n, a[maxn], ans;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > a[0]) {
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}