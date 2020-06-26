#include <iostream>
#include <algorithm>

const int maxn = 1e3+7;

int t, n, m, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			sum += a[i];
		}
		std::cout << std::min(m, sum) << '\n';
	}
}