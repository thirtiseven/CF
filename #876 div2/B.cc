#include <iostream>
#include <algorithm>
#include <string>
#include <set>

const int maxn = 2e5+7;
using ll = long long;

int t, n;
std::pair<int, ll> ab[maxn];

bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main(int argc, char *argv[]) {
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> ab[i].first >> ab[i].second;
		}
		std::sort(ab, ab+n, cmp);
		std::multiset<int> st;
		ll ans = 0;
		int x = 0, xx = 0;
		for (int i = 0; i < n; i++) {
			if (ab[i].first > xx) {
				ans += ab[i].second;
				st.insert(ab[i].first);
				x = st.size();
				xx = std::max(xx, x);
				while (st.size() > 0 && *st.begin() <= xx) {
//					std::cout << *st.begin() << "breaks " << '\n';
					st.erase(st.begin());
				}
//				std::cout << st.size() << ' ' << xx << '\n';
			}
		}
		std::cout << ans << '\n';
	}
}