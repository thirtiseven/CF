#include <iostream>
#include <string>

int T, n;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> s;
		std::string ans = "";
		for (int i = 0; i < n; i++) {
			if (int(s[i]-'0')%2==1 && ans.length() < 2) {
				ans += s[i];
			}
		}
		if (ans.length() < 2) {
			std::cout << "-1\n";
		} else {
			std::cout << ans << '\n';
		}
	}
}