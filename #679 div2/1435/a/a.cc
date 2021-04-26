#include <iostream>
#include <algorithm>

const int maxn = 123;

int T, n, a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < n; i += 2) {
			std::cout << (a[i] < 0? 1: -1)*std::abs(a[i+1]) << ' ' << (a[i+1] > 0? 1: -1)*std::abs(a[i]) << ' ';
		}
		std::cout << '\n';
	}
}