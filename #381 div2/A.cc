#include <iostream>
#include <algorithm>
#include <cmath>

int main(int argc, char *argv[]) {  
 	long long n, a, b, c;
	std::cin >> n >> a >> b >> c;
	long long left = 4 - n % 4;
	long long ans;
	if(left == 4) {
		ans = 0;
	} else if(left == 3) {
		ans = std::min(std::min(3 * a, c), b + a);
	} else if(left == 2) {
		ans = std::min(std::min(std::min(2 * a, b), 2 * c), a + b + c);
	} else if(left == 1) {
		ans = std::min(std::min(a, b + c), 3 * c);
	}
	std::cout << ans;
	return 0;
}