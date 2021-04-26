#include <iostream>
#include <algorithm>

int T, x, xx, y, yy, ans;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> x >> y >> xx >> yy;
		if (x == xx || y == yy) {
			ans = std::abs(y-yy)+std::abs(x-xx);
		} else {
			ans = std::abs(y-yy)+std::abs(x-xx)+2;
		}
		std::cout << ans << '\n';
	}
}