#include <iostream>

const int maxn = 123;

int T, n, k1, k2;
int a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n >> k1 >> k2;
		int amax = 0, bmax = 0;
		for (int i = 0; i < k1; i++) {
			std::cin >> a[i];
			amax = std::max(amax, a[i]);
		}
		for (int i = 0; i < k2; i++) {
			std::cin >> b[i];
			bmax = std::max(bmax, b[i]);
		}
		if (amax > bmax) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}