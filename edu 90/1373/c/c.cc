#include <iostream>
#include <algorithm>

using ll = long long;

int T;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		ll res = s.length();
		ll cur = 0, minn = 0;
		for (ll i = 0; i < s.length(); i++) {
			if (s[i] == '-') {
				cur--;
			} else {
				cur++;
			}
			if (cur < minn) {
				res += i+1;
				minn = cur;
			}
		}
		std::cout << res << '\n';
	}
}