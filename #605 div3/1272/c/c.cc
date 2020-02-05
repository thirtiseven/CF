#include <iostream>
#include <string>
#include <algorithm>

using ll = long long;

ll n, k, c[27];
std::string s;

int main(int argc, char *argv[]) {  
	std::cin >> n >> k >> s;
	char cha;
	std::fill(c, c+27, 0);
	for (int i = 0; i < k; i++) {
		std::cin >> cha;
		c[int(cha-'a')] = 1;
	}
	ll ans = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		if (c[int(s[i]-'a')] == 1) {
			cur++;
		} else {
			ans += (cur*(cur+1))/2;
			cur = 0;
		}
	}
	ans += (cur*(cur+1))/2;
	std::cout << ans << '\n';
}