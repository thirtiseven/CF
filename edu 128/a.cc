#include <iostream>
#include <algorithm>

int t, l1, r1, l2, r2;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> l1 >> r1 >> l2 >> r2;
		if ((l2 <= r1 && l2 >= l1)){
			std::cout << 
		} else if ((l1 <= r2 && l1 >= l2)) {
			std::cout << 
		}
	}
}