#include <iostream>
#include <iomanip>

int main(int argc, char *argv[]) {  
	unsigned long long k, d, t;
	std::cin >> k >> d >> t;
	double ans = 0;
	while (d < k) {
		d += d;
	}
	if (d == k) {
		std::cout << t;
	} else {
		t *= 2;
		ans += (t/(k+d))*d;
		t %= (k+d);
		if (t > 2 * k) {
			ans += k;
			ans += (t-2*k);
		} else {
			ans += double(t)/2.0;
		}
		std::cout << std::fixed << std::setprecision(10) << ans << std::endl;
	}
}