#include <iostream>

int main(int argc, char *argv[]) {  
	long long k, d, t;
	std::cin >> k >> d >> t;
	if (k%d == 0) {
		std::cout << t;
		return 0;
	}
	double ans;
	ans = double(t);
	ans += double((t/(d-k%d+k))*(d-k%d))*0.5;
	t %= (d-k%d+k);
	if (t > k) {
		t += double(t-k)*0.5;
	}
	std::cout << ans;
}