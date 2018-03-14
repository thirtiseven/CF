#include <iostream>
#include <cmath>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int ans = 0;
	int n, t;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		ans += std::abs(t);
	}
	std::cout << ans;
}