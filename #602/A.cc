#include <iostream>

int T;
int n, l, r, u, v;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		l = 1000004000, r = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> u >> v;
			r = std::max(u, r);
			l = std::min(v, l);
		}
		std::cout << std::max(r-l, 0) << '\n';
	}
}