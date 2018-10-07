#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		long long x, y, k;
		std::cin >> x >> y >> k;
		long long sum;
		int  flat = 0;
		if ((std::max(x,y)-std::min(x,y))%2==0) {
			sum = std::max(x,y);
		} else {
			sum = std::max(x,y)-1;
			flat = 1;
		}
		if (k < std::max(x, y)) {
			std::cout << "-1\n";
		} else if(x == y) {
			long long ans = 0;
			if ((k-x)%2==1) {
				ans = k-2;
			} else {
				ans = k;
			}
			std::cout << ans << '\n';
		} else {
			long long ans = k;
			if (flat == 0 && (k-sum)%2==1) {
				ans -= 2;
			}
			if (flat) {
				ans--;
			}
			std::cout << ans << '\n';
		}
	}
}