#include <iostream>
#include <algorithm>

int T;
int b, w;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> b >> w;
		if (std::max(b, w) <= 1 + 3 * std::min(b, w)) {
			std::cout << "YES\n";
			int x, y;
			if (b <= w) {
				x = 3, y = 1;
			} else {
				x = 2, y = 1;
				std::swap(b, w);
			}
			for (int i = 0; i < 2*b; i++) {
				std::cout << x << ' ' << y+i << '\n';
			}
			w -= b;
			if (w > 0) {
				std::cout << x << " " << y+2*b << '\n';
				w--;
			}
			int cnt = 2;
			for (int i = 0; i < w; i++) {
				if (i%2==0) {
					std::cout << x-1 << " " << cnt << '\n';
				} else {
					std::cout << x+1 << " " << cnt << '\n';
					cnt += 2;
				}
			}
		} else {
			std::cout << "NO\n";
		}
	}
}