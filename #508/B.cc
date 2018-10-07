#include <iostream>

bool is_prime(int n) {
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n, ans;
	std::cin >> n;
	int sum = (n + 1) * n / 2;
	if (sum == 1) {
		std::cout << "No\n";
	} else {
		if (is_prime(sum)) {
			std::cout << "No\n";
		} else {
			std::cout << "Yes\n";
			for(int i = 2; i * i <= sum; i++) {
				if(sum % i == 0) {
					std::cout << "1 " << i;
					ans = i;
					break;
				}
			}
			std::cout << "\n" << n-1;
			for (int i = 1; i <= n; i++) {
				if (ans != i) {
					std::cout << " " << i;
				}
			}
		}
	}
}