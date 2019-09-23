#include <iostream>
#include <algorithm>

const int maxn = 3e5+7;
using ll = long long;
const ll mod = 998244353;

bool cmp1(std::pair<int, int> a, std::pair<int, int> b) {
	return a.first < b.first;
}

bool cmp2(std::pair<int, int> a, std::pair<int, int> b) {
	return a.second < b.second;
}

std::pair<int, int> a[maxn], b[maxn], c[maxn];

ll fac[maxn];

void inti(int n) {
	fac[1] = 1;
	for (ll i = 2; i <= n; i++) {
		fac[i] = fac[i-1] * i % mod;
	}
}

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	inti(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
		b[i] = c[i] = a[i];
	}
	std::sort(a, a+n, cmp1);
	std::sort(b, b+n, cmp2);
	std::sort(c, c+n);
	ll ans1 = 1, ans2 = 1, ans3 = 1;
	int combo = 1;
	for (int i = 1; i < n; i++) {
		if (a[i].first == a[i-1].first) {
			combo++;
		} else {
			ans1 *= fac[combo];
			ans1 %= mod;
			combo = 1;
		}
	}
	if (combo > 1) {
		ans1 *= fac[combo];
		ans1 %= mod;
		combo = 1;
	}
	for (int i = 1; i < n; i++) {
		if (b[i].second == b[i-1].second) {
			combo++;
		} else {
			ans2 *= fac[combo];
			ans2 %= mod;
			combo = 1;
		}
	}
	if (combo > 1) {
		ans2 *= fac[combo];
		ans2 %= mod;
		combo = 1;
	}
	for (int i = 1; i < n; i++) {
		if (c[i].first == c[i-1].first && c[i].second == c[i-1].second) {
			combo++;
		} else {
			ans3 *= fac[combo];
			ans3 %= mod;
			combo = 1;
		}
	}
	if (combo > 1) {
		ans3 *= fac[combo];
		ans3 %= mod;
	}
	for (int i = 1; i < n; i++) {
		if (c[i].first < c[i-1].first || c[i].second < c[i-1].second) {
			ans3 = 0;
			break;
		}
	}
//	std::cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
	ll ans = ans1 + ans2;
	ans %= mod;
	ans += (mod-ans3);
	ans %= mod;
	ans = fac[n] + mod - ans;
	ans %= mod;
	std::cout << ans << '\n';
}