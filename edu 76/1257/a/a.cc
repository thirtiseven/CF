#include <iostream>
#include <algorithm>

int T;
int n, x, a, b;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n >> x >> a >> b;
		std::cout << std::min(n-1, std::abs(a-b)+x) << '\n';
	}
}