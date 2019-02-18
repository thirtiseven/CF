#include <iostream>
#include <algorithm>

using ll = unsigned long long;
const int maxn = 3e5+7;

ll a[maxn];

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	ll ans = 0;
	for (int i = 0; i < n/2; i++) {
		ans += (a[i]+a[n-1-i])*(a[i]+a[n-1-i]);
	}
	std::cout << ans;
}