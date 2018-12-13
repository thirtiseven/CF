#include <iostream>

int main(int argc, char *argv[]) {  
	int t;
	std::cin >> t;
	while (t--) {
		int a, v, l, r;
		std::cin >> a >> v >> l >> r;
		int anss = 0;
		anss = a/v;
		anss -= r/v;
		anss += (l-1)/v;
		std::cout << anss << '\n';
	}
}