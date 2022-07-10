#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using ll = long long;

const int maxn = 3e5+7;

ll T, n, m, k, x[maxn], y[maxn];
std::pair<int, int> p[maxn];

bool cmp1(std::pair<int, int> a, std::pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

bool cmp2(std::pair<int, int> a, std::pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

ll gao(std::map<ll, int> x) {
	if (x.size() == 0) {
		return 0;
	}
	ll res = 0;
	ll sum = 0;
//	std::cout << "-----\n";
	for (auto it: x) {
//		std::cout << it.first << ' ' << it.second << " | ";
		sum += it.second;
	}
//	std::cout << "\n-----\n";
	for (auto it: x) {
		res += (sum-it.second)*it.second;
	}
	return res/2;
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			std::cin >> x[i];
		}
		for (int i = 0; i < m; i++) {
			std::cin >> y[i];
		}
		for (int i = 0; i < k; i++) {
			std::cin >> p[i].first >> p[i].second;
		}
		
		ll ans = 0;
		
		std::sort(p, p+k, cmp1);
		ll nowx = 0;
		std::map<ll, int> tmp;
//		for (int i = 0; i < k; i++) {
//			std::cerr << p[i].first << ' ';
//		}
//		std::cerr << '\n';
		for (int i = 0; i < k; i++) {
			while (p[i].first > x[nowx]) {
				nowx++;
				ans += gao(tmp);
				tmp.clear();
			}
			if (p[i].first < x[nowx]) {
				tmp[p[i].second]++;
			}
		}
		if (tmp.size()) {
			ans += gao(tmp);
		}
		
		std::sort(p, p+k, cmp2);
		ll nowy = 0;
		tmp.clear();
		
		for (int i = 0; i < k; i++) {
			while (p[i].second > y[nowy]) {
				nowy++;
				ans += gao(tmp);
				tmp.clear();
			}
			if (p[i].second < y[nowy]) {
				tmp[p[i].first]++;
			}
		}
		if (tmp.size()) {
			ans += gao(tmp);
		}
		
		std::cout << ans << '\n';
	}
}