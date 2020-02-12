#include <iostream>
#include <algorithm>
#include <cmath>

const int maxn = 2e5+7;

int T, n, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n*2; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n+n);
		std::cout << std::abs(a[n]-a[n-1]) << '\n';
	}
}