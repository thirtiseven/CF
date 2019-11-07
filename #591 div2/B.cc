#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int q;
	std::cin >> q;
	while (q--) {
		std::string s, t;
		std::cin >> s >> t;
		int cs[30], ct[30];
		std::fill(cs, cs+30, 0);
		std::fill(ct, ct+30, 0);
		bool yes = 0;
		for (int i = 0; i < s.length(); i++) {
			cs[int(s[i]-'a')]++;
			ct[int(t[i]-'a')]++;
		}
		for (int i = 0; i < 26; i++) {
			if (cs[i] > 0 && ct[i] > 0) {
				yes = 1;
			}
		}
		if (yes) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}