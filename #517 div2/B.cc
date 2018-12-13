#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int n, a[maxn], b[maxn], c[maxn], ans;

int main(int argc, char *argv[]) {
	std::cin >> n;
	for (int i = 1; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		std::cin >> b[i];
	}
	for (int k = 0; k <= 3; k++) {
		c[1] = k;
		bool yes = 1;
		for (int i = 1; i < n; i++) {
			c[i+1] = a[i] + b[i] - c[i];
			if ((c[i+1]&c[i]) != b[i]) {
				yes = 0;
				break;
			}
			if ((c[i+1]|c[i]) != a[i]) {
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << "YES\n";
			for (int i = 1; i <= n; i++) {
				std::cout << c[i] << ' ';
			}
			exit(0);
		}
	}
	std::cout << "NO";
}