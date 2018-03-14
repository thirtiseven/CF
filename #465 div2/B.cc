#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	int n;
	std::cin >> n >> s;
	int u = 0, r = 0;
	int ans = 0;
	for (int i = 0; i < s.length()-1; i++) {
		if (s[i] == 'U') {
			u++;
		} else {
			r++;
		}
		if (r == u && s[i+1] == s[i]) {
			ans++;
		}
	}
	std::cout << ans;
}