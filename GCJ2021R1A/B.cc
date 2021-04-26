#include <iostream>
#include <algorithm>

const int maxm = 105;

using ll = long long;

int T, M;
ll P[maxm], N[maxm], sum, num[maxm], cnt, ans;

void dfs(ll x, ll mul, ll tot) {
	if (x >= cnt) {
		return;
	}
	std::cout << x << ' ' << num[x] << ' ' << mul << '\n';
	if (sum - tot == mul && mul != 1) {
		ans = std::max(ans, mul);
		return;
	}
	ll temp = mul * num[x];
	if (temp > sum) {
		return;
	}
	dfs(x+1, mul, tot);
	dfs(x+1, temp, tot + num[x]);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		sum = 0;
		cnt = 0;
		ans = 0;
		std::cin >> M;
		for (int i = 0; i < M; i++) {
			std::cin >> P[i] >> N[i];
			sum += P[i] * N[i];
			for (int j = 0; j < N[i]; j++) {
				num[cnt] = P[i];
				cnt++;
			}
		}
		dfs(0, 1, 0);
		std::cout << "Case #" << CAS << ": " << ans << '\n';
	}
}