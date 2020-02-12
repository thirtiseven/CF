#include <iostream>

int T;
int n, a[123];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		int sum = 0, zero = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			sum += a[i];
			if (a[i] == 0) {
				zero ++;
			}
		}
		int ans = zero;
		if (sum + zero == 0) {
			ans++;
		}
		std::cout << ans << '\n';
	}
}