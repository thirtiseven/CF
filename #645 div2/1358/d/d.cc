#include <iostream>
#include <algorithm>

using ll = long long;

const int maxn = 4e5+7;

ll n, x, d[maxn];

ll cal(ll l, ll r) {
	if (l > r || r == 0) {
		return 0;
	}
	return (l+r)*(r-l+1)/2;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		std::cin >> d[i];
		d[n+i] = d[i];
	}
	n = 2*n;
	ll head = 1, headstart = 1, headend = d[1];
	ll cur = 0, sum = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		cur += d[i];
		sum += cal(1, d[i]);
		if (cur >= x) {
			cur -= x;
			while (cur >= headend-headstart+1) {
				cur -= (headend-headstart+1);
				sum -= cal(headstart, headend);
				head++;
				headstart = 1;
				headend = d[head];
			}
			sum -= cal(1, cur);
			headstart = cur+1;
			headend = d[head];
			cur = x;
//			std::cout << i << ' ' << sum << ' ' << ans << '\n';
			ans = std::max(ans, sum);
		}
	}
	std::cout << ans << '\n';
}