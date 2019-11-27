#include <iostream>
#include <algorithm>

const int maxn = 200000+7;

long long n, m, a[maxn], ans;

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	for (int i = 0; i < n; i++) {
		if (i-m >= 0) {
			a[i] += a[i-m];
		}
 	}
	for (int i = 0; i < n; i++) {
		ans += a[i];
		std::cout << ans << ' ';
	}
}