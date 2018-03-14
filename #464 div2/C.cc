#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	long long n, a[123456], s, f;
	std::cin >> n;
	for (long long i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::cin >> s >> f;
	long long seg = f - s;
	long long sum = 0, maxx = -1;
	for (long long i = 1; i <= seg; i++) {
		sum += a[i];
	}
	maxx = sum;
	long long ans = 1;
//	std::cout << seg << "\n";
	for (long long i = 2; i <= n; i++) {
//		std::cout << i-1 << " " << (((i+seg-2)%n)+1) << " " << sum << " ";
		sum -= a[i-1];
		sum += a[((i+seg-2)%n)+1];
//		std::cout << sum << "\n";
		if (sum == maxx) {
			ans = std::min(ans, (i+s-1)%n+1);
		} else if (sum > maxx) {
			maxx = sum;
			ans = (i+s-1)%n+1;
		}
	}
//	std::cout << ans << '\n' << maxx << '\n';
	std::cout << ans;
}