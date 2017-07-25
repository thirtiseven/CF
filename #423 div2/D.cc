#include <iostream>

int main(int argc, char *argv[]) {
	int n, k, ans;
	std::cin >> n >> k;
	if((n - 1) % k == 0) {
		ans = (n - 1) / k * 2;
	} else if((n - 1) % k == 1) {
		ans = (n - 1) / k * 2 + 1;
	} else {
		ans = (n - 1) / k * 2 + 2;
	}
	std::cout << ans << std::endl;
	for(int i = 2; i <= k + 1; i++){
		std::cout << i << " 1\n";
	}
	for(int i = 2; i <= n - k; i++) {
		std::cout << i << " " << i + k << "\n";
	}
	return 0;
}