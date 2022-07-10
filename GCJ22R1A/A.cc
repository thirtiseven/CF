#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 123;

int n;
std::string s;
char suf[maxn];

char next(int x) {
	for (int i = x+1; i <= s.length(); i++) {
		if (s[i] != s[x]) {
			return s[i];
		}
	}
	return 'A'-1;
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int CAS = 1; CAS <= n; CAS++) {
		std::cin >> s;
		std::string ans = "";
		int l = s.length();
		suf[l] = 'A'-1;
		for (int i = l-1; i >= 0; i--) {
			suf[i] = std::max(suf[i+1], s[i]);
		}
		for (int i = 0; i < l; i++) {
			if (i < l-1 && s[i] <= next(i)) {
				ans += s[i];
				ans += s[i];
			} else {
				ans += s[i];
			}
		}
		std::cout << "Case #" << CAS << ": " << ans << '\n';
	}
}