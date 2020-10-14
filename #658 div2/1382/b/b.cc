#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

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
		int x = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				x++;
			} else {
				break;
			}
		}
		if (x != n) {
			if (x % 2 == 0) {
				std::cout << "First\n";
			} else {
				std::cout << "Second\n";
			}
		} else {
			if (x % 2 == 1) {
				std::cout << "First\n";
			} else {
				std::cout << "Second\n";
			}
		}
	}
}