#include <iostream>
#include <algorithm>

int t, n, m;
int a, b, c, d;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		bool sym = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a >> b >> c >> d;
			if (b == c) {
				sym = 1;
			}
		}
		if (m % 2 == 1 || sym == 0) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
		}
	}
}