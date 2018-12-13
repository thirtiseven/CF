#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	long long n, m;
	std::cin >> n >> m;
	long long ans1, ans2;
	long long l = 0, r = 1e5;
	long long mid;
	while (l<=r) {
		mid = (l+r)/2;
		if (mid*(mid-1)/2 >= m) {
			r = mid-1;
		} else {
			l = mid+1;
		}
//		std::cout << mid << " " << mid*(mid-1)/2 << " " << l << " " << r << '\n';
	}
//	std::cout << l << '\n';
	ans1 = std::max(0LL, n-l);
	ans2 = std::max(0LL, n-(m*2));
	std::cout << ans2 << " " << ans1;
}