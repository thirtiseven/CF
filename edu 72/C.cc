#include <iostream>
#include <string>
std::string s;
int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		int ans = 0;
		int now = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') {
				now++;
			} else {
				ans++;
				int cur = 1;
				for (int j = 1; cur <= s.length() && i+j < s.length(); j++) {
					cur<<=1;
					if (s[i+j] == '1') {
						cur++;
					}
					if (cur <= now+j+1) {
						ans++;
					} else {
						break;
					}
				}
				now = 0;
			}
		}
		std::cout << ans << '\n';
	}
}