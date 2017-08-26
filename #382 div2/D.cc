#include <iostream>
#include <cmath>
/*
bool is_prime(int alice) {
	int max_bound = sqrt(alice);
	if(alice % 2 == 0 || alice <= 2) {
		return false;
	}
	for(int i = 3; i <= max_bound; i += 2) {
		if(alice % i == 0) {
			return false;
		}
	}
	return true;
}*/

bool is_prime(int n) {
	if(n < 2)return false;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0)return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	int n, ans;
	std::cin >> n;
	if(is_prime(n)) {
		ans = 1;
	} else if(n % 2 == 0 || is_prime(n - 2)) {
		ans = 2;
	} else {
		ans = 3;
	}
	std::cout << ans << std::endl;
}