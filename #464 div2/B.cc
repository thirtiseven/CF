#include <iostream>

const int maxn = 1e5+7;

int main(int argc, char *argv[]) {  
	long long n, k, a[maxn];
	std::cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		std::cin >> a[i];
	}
	long long ans1, ans2;
	long long maxx = 100000000000000;
	for (int i = 1; i <= k; i++) {
		if (n%a[i] < maxx) {
			maxx = n%a[i];
			ans1 = i;
			ans2 = n/a[i];
		}
	}
	std::cout << ans1 << " " << ans2;
}