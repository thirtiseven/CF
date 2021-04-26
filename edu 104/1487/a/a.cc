#include <iostream>
#include <algorithm>

int t, n, a[123];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		a[n] = 200;
		std::sort(a, a+n);
		int x = 1;
		while (a[x] == a[0]) {
			x++;
		}
		std::cout << n-x << '\n';
	}
}