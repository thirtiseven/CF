#include <iostream>
#include <algorithm>

const int maxn = 2008;

int n, k, a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::sort(a, a+n);
	std::sort(b, b+n);
	for (int i = 0; i < n; i++) {
		int x = (b[i]+k-a[0])%k;
		bool yes = 1;
		for (int j = 0; j < n; j++) {
			if (b[(j+i)%n] != (a[j]+x)%k) {
				yes = 0;
				break;
			}
		}
		if (yes == 1) {
			std::cout << x << '\n';
			exit(0);
		}
	}
}