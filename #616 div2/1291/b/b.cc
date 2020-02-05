#include <iostream>

const int maxn = 3e5+7;

int a[maxn], n, T;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
//			yes[i] = 0;
		}
		int l = -1, r = n;
		for (int i = 0; i < n; i++) {
			if (a[i] >= i) {
				l = i;
			} else {
				break;
			}
		}
		for (int i = n-1; i >= 0; i--) {
			if (a[i] >= n-i-1) {
				r = i;
			} else {
				break;
			}
		}
//		std::cout << l << ' ' << r << '\n';
		if (l >= r || (l == r-1 && a[l] != a[r])) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}
}