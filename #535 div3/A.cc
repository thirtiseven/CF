#include <iostream>

int main(int argc, char *argv[]) {  
	int q, l1, r1, l2, r2;
	std::cin >> q;
	while (q--) {
		std::cin >> l1 >> r1 >> l2 >> r2;
		if (l1 != l2) {
			std::cout << l1 << " " << l2 << '\n';
		} else {
			std::cout << l1 << " " << r2 << '\n';
		}
	}
}