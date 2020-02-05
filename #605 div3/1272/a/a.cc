#include <iostream>
#include <algorithm>

long long T, a[4];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> a[0] >> a[1] >> a[2];
		long long ans = 10000000000;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				for (int k = -1; k <= 1; k++) {
					ans = std::min(ans, std::abs((a[0]+i)-(a[1]+j)) + std::abs((a[0]+i)-(a[2]+k)) + std::abs((a[1]+j)-(a[2]+k)));
				}
			}
		}
		std::cout << ans << '\n';
	}
}