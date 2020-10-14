#include <iostream>
#include <algorithm>

const int maxn = 123;

int t, n, k, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		int num = 0;
		a[0] = -1;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			if (a[i] != a[i-1]) {
				num++;
			}
		}
//		std::cout << num << ' ' << k << '\n';
		if (num > 1 && k == 1) {
			std::cout << "-1\n";
		} else if (num <= k) {
			std::cout << "1\n";
		} else {
			std::cout << (num-2)/(k-1)+1 << '\n';
		}
	}
}