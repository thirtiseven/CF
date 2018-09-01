#include <iostream>
#include <string>

std::string s;

int main(int argc, char *argv[]) {  
	std::cin >> s;
	int ans = 0;
	int now = 1;
	int len = s.length();
	for (int i = 1; i < len; i++) {
		if (s[i] != s[i-1]) {
			now++;
		} else {
			ans = std::max(now, ans);
			now = 1;
		}
	}
	ans = std::max(now, ans);
	now = 0;
	if (s[0] == s[len-1] || ans == len) {
		std::cout << ans << '\n';
	} else {
		int pre  = 1, sa = 1;
		for (int i = 1; i < len; i++) {
			if (s[i] != s[i-1]) {
				pre++;
			} else {
				break;
			}
		}
		for (int i = len-2; i >= 0; i--) {
			if (s[i] != s[i+1]) {
				sa++;
			} else {
				break;
			}
		}
		ans = std::max(ans, sa+pre);
		std::cout << ans << '\n';
	}
}