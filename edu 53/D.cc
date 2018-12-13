#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>

std::ifstream fin ("aaa.in"); 

using ll = long long;
const int maxn = 2e5+10;

ll n, T, a[maxn];
std::pair<ll, ll> b[maxn];
ll tree[maxn];

void add(int i, ll x) {
	for(;i <= n; i += i & -i)
		tree[i] += x;
}

ll sum(int i) {
	ll ret = 0;
	for(; i; i -= i & -i) ret += tree[i];
	return ret;
}


int main(int argc, char *argv[]) {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);  
	std::cout << "test0\n";
	std::fill(tree, tree+maxn, 0);
	std::cout << "test1\n";
	fin >> n >> T;
	std::cout << "test2\n";
	for (int i = 1; i <= n; i++) {
		fin >> a[i];
		b[i].first = a[i];
		b[i].second = i;
		add(i, a[i]);
	}
	std::cout << "test3\n";
	std::sort(b+1, b+n+1);
	ll now = n;
	ll cnt = n;
	ll ans = 0;
	while (T >= b[1].first) {
//		std::cout << T << ' ';
		while (T < b[now].first && now > 0) {
			add(b[now].second, -a[b[now].first]);
			now--;
			cnt--;
		}
		if (now < 1) break;
		ll summ = sum(n);
		if (summ == 0) break;
		if (T >= summ) {
			ans += cnt*(T/summ);
			T %= summ;
		} else {
			for (int i = 1; i <= n; i++) {
				if (a[i] <= T && T > 0) {
					T -= a[i];
					ans++;
				}
			}
		}
	}
	std::cout << ans << '\n';
}