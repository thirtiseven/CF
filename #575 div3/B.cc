#include <iostream>
#include <vector>

const int maxn = 2e5+7;
using ll = long long;

ll T, n, k;
ll a[maxn];

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	ll sum = 0, cnt = 0;
	while (T--) {
		std::vector<ll> ans;
		std::cin >> n >> k;
		ll cur = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			cur += a[i];
			if (cur % 2 == 1 && ans.size() < k-1) {
				ans.push_back(i);
				cur = 0;
			}
		}
		if (cur % 2 == 1) {
			ans.push_back(n);
			std::cout << "YES\n";
			for (auto it: ans) {
				std::cout << it << " ";
			}
			std::cout << '\n';
		} else {
			std::cout << "NO\n";
		}
	}
}