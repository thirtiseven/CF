#include <iostream>
#include <algorithm>
#include <string>
#include <map>

int t, n;
std::string s;
std::map<char, int> mp;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		mp.clear();
		std::cin >> n;
		for (int i = 0; i < 2 * n + 1; i++) {
			std::cin >> s;
			for (auto it: s) {
				mp[it]++;
			}
		}
		char ans = '?';
		for (auto it: mp) {
			if (it.second % 2 == 1) {
				ans = it.first;
				break;
			}
		}
		std::cout << ans << '\n';
	}
}