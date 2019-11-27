#include <iostream>

const int maxn = 100000+8;

int n, t, a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		bool use = 0;
		int l, r, k = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> b[i];
			if (b[i] != a[i] && !use) {
				k = b[i]-a[i];
				l = i;
				use = 1;
			}
			if (b[i] != a[i]) {
				r = i;
			}
		}
		for (int i = l; i <= r; i++) {
			b[i] -= k;
		}
		bool yes = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				yes = 0;
			}
		}
		if (yes && k >= 0) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}