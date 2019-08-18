#include <iostream>
#include <algorithm>

const int maxn = 100000;

using ll = long long;
ll n, x1, x2;

bool cmp(std::pair<ll, ll> a, std::pair<ll, ll> b) {
	if (a.first * x1 + a.second == b.first * x1 + b.second) {
		return a.first * x2 + a.second < b.first * x2 + b.second;
	}
	return a.first * x1 + a.second < b.first * x1 + b.second;
}

int main(int argc, char *argv[]) {  
	std::pair<ll, ll> kb[maxn];
	std::cin >> n;
	std::cin >> x1 >> x2;
	for (ll i = 0; i < n; i++) {
		std::cin >> kb[i].first >> kb[i].second;
	}
	std::sort(kb, kb+n, cmp);
	bool yes = 0;
	ll now = kb[0].first * x2 + kb[0].second;
	for (ll i = 1; i < n; i++) {
		if (kb[i].first * x2 + kb[i].second < now) {
			yes = 1;
			break;
		}
		now = kb[i].first * x2 + kb[i].second;
	}
	if (yes) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}