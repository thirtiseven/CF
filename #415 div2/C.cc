#include <iostream>
#include <algorithm>
#define maxn 300010

int main(int argc, char *argv[]) {  
	long long ans = 0, n, a[maxn], sum[maxn];
	std::cin >> n;
	sum[0] = 1;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum[i] = (2 * sum[i - 1]) % 1000000007;
	}
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		ans = (ans + (sum[i - 1] - sum[n - i]) * a[i]) % 1000000007;
	}
	std::cout << ans << std::endl;
	return 0;
}


