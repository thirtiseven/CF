#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using ll = long long;
int T;
ll n, x, y;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		std::cin >> n >> x >> y;
		ll sum = (1LL+n)*n/2;
		if (sum % (x+y) != 0) {
			std::cout << "Case #" << cas << ": IMPOSSIBLE\n";
			continue;
		}
		ll ala = sum * x / (x+y);
		ll cur = n;
		ll sumans = ala;
//		std::cout << ala << ' ' << cur << '\n';
		std::vector<ll> ans;
		while (sumans > 0) {
			if (sumans == cur) {
				sumans = 0;
				ans.push_back(cur);
				break;
			} else if (sumans > cur) {
				sumans -= cur;
				ans.push_back(cur);
				cur--;
			} else {
				cur--;
			}
		}
		std::sort(ans.begin(), ans.end());
		std::cout << "Case #" << cas << ": POSSIBLE\n";
		std::cout << ans.size() << '\n';
		for (auto it: ans) {
			std::cout << it << ' ';
		}
		std::cout << '\n';
	}
}