#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int T, n, a[maxn], b[maxn], aa[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			aa[i] = a[i];
		}
		for (int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		std::sort(aa, aa+n);
		bool sorted = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] != aa[i]) {
				sorted = 0;
			}
		}
		std::sort(b, b+n);
		bool diff = 0;
		if (b[0] != b[n-1]) {
			diff = 1;
		}
		if (sorted || diff) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}
}