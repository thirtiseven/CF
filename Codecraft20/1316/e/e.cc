#include <iostream>

using ll = long long;
const int maxn = 1e5+7;

ll n, p, k;
ll a[maxn];
ll s[maxn][8];
ll dp[maxn][258];
ll cur[8];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> p >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < p; j++) {
			std::cin >> s[i][j];
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (1<<(p+1)); j++) {
			for (int k = 0; k < p; k++) {
				if (j >>(k) & 1 == 0) {
					dp[i][j|(1<<(k))] = std::max(dp[i][j|(1<<(k))], dp[i-1][j]+a[k]);
				}
			}
		}
	}
}