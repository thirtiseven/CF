#include <iostream>

const int maxn = 123;

int T, n, p[maxn], c[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		bool yes = 1;
		for (int i = 0; i < n; i++) {
			std::cin >> p[i] >> c[i];
			if (c[i] > p[i]) {
				yes = 0;
			}
		}
		if (yes) {
			for (int i = 1; i < n; i++) {
				if (c[i] < c[i-1] || p[i] < p[i-1] || c[i]-c[i-1] > p[i]-p[i-1]) {
					yes = 0;
					break;
				}
 			}
		}
		std::cout << (yes?"YES\n":"NO\n");
	}
}