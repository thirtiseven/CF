#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	long long ans = 0;
	for (int i = 0; i < s.length(); i++) {
		int l = 0, r = 0;
		for (int j = i; j < s.length(); j++) {
			if (s[j] == '(') {
				l++, r++;
			} else if (s[j] == ')') {
				l--, r--;
			} else {
				l--, r++;
			}
			if (l < 0) {
				l += 2;
			}
			if (r < 0) {
				break;
			}
			if (l == 0) {
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
	return 0;
}