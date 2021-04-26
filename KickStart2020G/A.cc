#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;
const int maxn = 1e5+7;

std::string s;
int T;
int start[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		std::cin >> s;
		ll ans = 0;
		if (s.length() < 9) {
			std::cout << "Case #" << CAS << ": " << 0 << '\n';
			continue;
		}
		for (int i = s.length()-4; i < s.length(); i++) {
			start[i] = 0;
		}
		for (int i = s.length()-5; i >= 0; i--) {
			if (s.substr(i, 5) == "START") {
				start[i] = start[i+1]+1;
			} else {
				start[i] = start[i+1];
			}
		}
		for (int i = 0; i < s.length()-8; i++) {
			if (s.substr(i, 4) == "KICK") {
				ans += start[i+4];
			}
		}
		std::cout << "Case #" << CAS << ": " << ans << '\n';
	}
}