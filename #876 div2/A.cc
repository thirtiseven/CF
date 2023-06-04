#include <iostream>
#include <algorithm>
#include <string>

int t, n, k;

const int maxn = 123;
int a[maxn];

int main(int argc, char *argv[]) {
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		int one = 0;
		for (int i = 0; i < n-1; i++) {
			if ((i)/k+1 > one) {
				a[i] = 1;
				one++;
			} else {
				a[i] = 0;
			}
		}
		int half_one = 0;
		for (int i = 0; i < n/2; i++) {
			if (a[i] == 1) {
				half_one++;
			}
		}
		int ans = 0;
		if (half_one * 2 < one) {
			ans = half_one * 2 + 1;
		} else {
			ans = one;
		}
//		std::cout << '\n';
		std::cout << ans + 1 << '\n';
	}
}
