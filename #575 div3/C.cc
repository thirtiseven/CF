#include <iostream>
#include <algorithm>

const int range = 1e5;

int T, n;
int x, y, f[5];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		int up = range, left = -range, right = range, down = -range;
		for (int i = 0; i < n; i++) {
			std::cin >> x >> y >> f[1] >> f[2] >> f[3] >> f[4];
			if (f[1] == 0) {
				left = std::max(left, x);
			}
			if (f[2] == 0) {
				up = std::min(up, y);
			}
			if (f[3] == 0) {
				right = std::min(right, x);
			}
			if (f[4] == 0) {
				down = std::max(down, y);
			}
		}
		if (down > up || left > right) {
			std::cout << "0\n";
		} else {
			std::cout << "1 " << left << ' ' << up << '\n';
		}
	}
}