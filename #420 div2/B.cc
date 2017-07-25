#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {
	long long m, b, sum, ans = 0;
	std::cin >> m >> b;
	for(int i = b; i >= 0; i--) {
		sum = ((m * (b - i) + 1) * m * (b - i) / 2) * (i + 1) + (i * (i + 1) / 2) * (m * (b - i) + 1);
		ans = std::max(sum, ans);
	}
	std::cout << ans << std::endl;
	return 0;
}