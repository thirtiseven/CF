#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;

const int maxn = 23454;

bool cmp1(std::pair<ll, ll> a, std::pair<ll, ll> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first > b.first;
}

bool cmp2(std::pair<ll, ll> a, std::pair<ll, ll> b) {
	return a.second < b.second;
}

int main(int argc, char *argv[]) {  
	ll n, k, t;
	std::vector<std::pair<ll, ll>> b;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		b.push_back(std::make_pair(t, i));
	}
	std::sort(b.begin(), b.end(), cmp1);
	b.erase(b.begin()+k, b.end());
//	std::cout << b.size() << '\n';
	std::sort(b.begin(), b.end(), cmp2);
	ll ans = 0;
	for (auto it: b) {
		ans += it.first;
	}
	std::cout << ans << '\n';
	if (k == 1) {
		std::cout << n << '\n';
		exit(0);
	}
	std::cout << b[0].second + 1;
	for (int i = 1; i < k; i++) {
		if (i == k-1) {
			std::cout << " " << n-1-b[i-1].second;
			break;
		}
		std::cout << " " << b[i].second-b[i-1].second;
	}
}