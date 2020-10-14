#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;
const ll maxn = 200010;
const ll mod = 1e9+7;

ll n, a[maxn], c[maxn], pre[maxn], shu[maxn], k;
std::string s;
ll power[maxn];

void init() {
	power[0] = 1;
	for (int i = 1; i <= n; i++) {
		power[i] = power[i-1] * 3;
		power[i] %= mod;
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> s;
	k = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			k++;
		}
	}
	init();
	a[0] = int(s[0] == 'a');
	pre[0] = int(s[0] == '?');
	for (int i = 1; i < n; i++) {
		a[i] = a[i-1] + int(s[i] == 'a');
		pre[i] = pre[i-1] + int(s[i] == '?');
	}
	c[n] = 0;
	shu[n] = 0;
	for (int i = n-1; i >= 0; i--) {
		c[i] = c[i+1] + int(s[i] == 'c');
		shu[i] = shu[i+1] + int(s[i] == '?');
	}
	ll ans = 0;
	for (int i = 1; i < n-1; i++) {
		if (s[i] == 'b') {
			ans += a[i-1] * c[i+1] * power[k];
			ans += a[i-1] * shu[i+1] * power[k-1];
			ans += pre[i-1] * c[i+1] * power[k-1];
			ans += pre[i-1] * shu[i+1] * power[k-2];
			ans %= mod;
		} else if (s[i] == '?') {
			ans += a[i-1] * c[i+1] * power[k-1];
			ans += a[i-1] * shu[i+1] * power[k-2];
			ans += pre[i-1] * c[i+1] * power[k-2];
			ans += pre[i-1] * shu[i+1] * power[k-3];
			ans %= mod;
		}
	}
	std::cout << ans << '\n';
}