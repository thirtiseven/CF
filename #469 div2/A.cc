#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int l, r, a;
	std::cin >> l >> r >> a;
	if (l < r) {
		if (a > (r-l)) {
			a -= (r-l);
			l = r;
		} else {
			l += a;
			std::cout << 2*l;
			return 0;
		}
		std::cout << 2*l+(a/2)*2;
	} else if (r < l) {
		if (a > (l-r)) {
			a -= (l-r);
			r = l;
			std::cout << 2*r+(a/2)*2;
		} else {
			r += a;
			std::cout << 2*r;
		}
	} else {
		std::cout << 2*l + (a/2)*2;
	}
}