#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 105;

std::pair<ll, ll> blow[maxn];

bool cmp(std::pair<ll, ll> a, std::pair<ll, ll> b) {
	return a.first-a.second > b.first-b.second;
}

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		ll n, x;
		std::cin >> n >> x;
		ll maxx = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> blow[i].first >> blow[i].second;
			maxx = std::max(blow[i].first, maxx);
		}
		std::sort(blow, blow+n, cmp);
		ll xx = blow[0].first-blow[0].second;
		if ((xx > 0) || (x <= maxx)) {
			if (x <= maxx) {
				std::cout << "1\n";
 			} else {
				x -= maxx;
				x += (xx-1);
				std::cout << x/xx+1 << '\n';
			}	
		} else {
			std::cout << "-1\n";
		}
	}
}