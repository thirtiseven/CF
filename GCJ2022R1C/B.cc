#include <iostream>
#include <algorithm>

const int maxn = 1007;

using ll = long long;

int T, n, k;

ll a[maxn];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		std::cin >> n;
		ll left = 0, right = 0;
		for (int i = 0 ; i < n; i++) {
			std::cin >> a[i];
			left += a[i];
			right += a[i]*2;
		}
		std::cout << left << ' ' << right << '\n';
		ll upper = (right - left * left);
		ll lower = 2 * left;
		ll ans;
		if (lower == 0) {
			ans = 1;
		} else {
			ans = upper / lower;
		}
		std::cout << upper << ' ' << lower << '\n';
		if (lower == 0) {
			std::cout << "Case #" << CAS << ": " << "1" << '\n';
		} else if (upper % lower == 0) {
			std::cout << "Case #" << CAS << ": " << upper / lower << '\n';
		} else {
			std::cout << "Case #" << CAS << ": " << "IMPOSSIBLE\n";
		}
	}
}