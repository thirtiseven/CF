#include <iostream>
#include <algorithm>

const int maxn = 123;

int t, n, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		std::reverse(a, a+n);
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << " \n"[i==n-1];
		}
	}
}