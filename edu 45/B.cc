#include <iostream>
#include <algorithm>
#include <map>

const int maxn = 2e5+9;
using ll = int;
ll a[maxn], n, k;
std::map<ll, int> m;

int main(int argc, char *argv[]) {  
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		m[a[i]]++;
	}
	ll ans = 0;
	std::pair<ll, ll> t;
	ll cnt = 0;
	for (auto i : m) {
		if (cnt == 0) {
			t.first = i.first;
			t.second = i.second;
			cnt++;
			continue;
		}
		if (i.first > t.first && i.first <= t.first + k) {
			ans += t.second;
		}
		t.first = i.first;
		t.second = i.second;
	}
	std::cout << n-ans;
}