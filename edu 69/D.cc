#include <iostream>

using ll = long long;
const ll maxn = 3e5+7;
ll n, m, k;
ll a[maxn], dp[maxn], num[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> m >> k;
	ll ans = 0;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		dp[i] = dp[i-1] + a[i];
		num[i] = num[i-1] + 1;
		if (num[i] % m == 0) {
			dp[i] -= k;
		}
		if (dp[i] < 0) {
			dp[i] = 0;
			num[i] = 0;
		}
		ans = std::max(ans, (num[i] % m == 0)?dp[i]:dp[i]-k);
	}
	std::cout << ans << '\n';
}