#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, a, b;
	std::string s;
	std::cin >> n >> a >> b >> s;
	int t = 0, tot = 0;
	int odd = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '.') {
			t++;
			tot++;
		} else {
			if (t%2==1) {
				odd++;
			}
			t=0;
		}
	}
	if (t%2==1) {
		odd++;
	}
	int ans = 0;
	int aa = (tot-odd)/2+odd, bb = (tot-odd)/2;
	if (std::max(a, b) > aa) {
		ans += aa;
	} else {
		ans += std::max(a, b);
	}
	if (std::min(a, b) < bb) {
		ans += bb;
	} else {
		ans += std::min(a, b);
	}
	std::cout << std::min(ans, tot);
}