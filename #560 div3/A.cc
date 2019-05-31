#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n, x, y;
	std::string s;
	std::cin >> n >> x >> y >> s;
	int ans = 0;
	for (int i = s.length()-x; i < s.length(); i++) {
		if (i == s.length()-y-1 && s[i] != '1') {
			ans++;
		} else if (i != s.length()-y-1 && s[i] == '1') {
			ans++;
		}
	}
	std::cout << ans << '\n';
}