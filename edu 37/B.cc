#include <iostream>
#include <algorithm>
#include <cmath>

int main(int argc, char *argv[]) {  
	int n, pos, l, r;
	std::cin >> n >> pos >> l >> r;
	int ans = 0;
	if(l != 1 && r != n) {
		ans = std::min(std::abs(pos-r), std::abs(pos-l)) + r - l + 2;
	} else if(l != 1) {
		ans = std::abs(pos - l) + 1;
	} else if(r != n) {
		ans = std::abs(pos - r) + 1;
	} else {
		ans = 0;
	}
	std::cout << ans;
	return 0;
}