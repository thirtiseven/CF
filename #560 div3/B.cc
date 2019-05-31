#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int n, a[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= ans+1) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}