#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 130;

int n;
ll d[maxn], cnt[10003];

int main(int argc, char *argv[]) {  
	std::fill(cnt, cnt+10003, 0);
	std::cin >> n;
	for (ll i = 0; i < n; i++) {
		std::cin >> d[i];
		cnt[d[i]]++;
	}
	std::sort(d, d+n);
	for (ll i = 1; i <= d[n-1]; i++) {
		if (d[n-1]%i==0) cnt[i]--;
	}
	ll ans = 0;
	for (int i = d[n-1]; i >= 1; i--) {
		if (cnt[i] == 1) {
			ans = i;
			break;
		}
	}
	std::cout << d[n-1] << " " << ans << '\n';
}