#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 1e5+7;

int t, n, s[maxn];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	for (int CAS = 1; CAS <= t; CAS++) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
		}
		std::sort(s, s+n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] >= ans+1) {
				ans += 1;
			}
		}
		std::cout << "Case #" << CAS << ": " << ans << '\n';	
	}
}