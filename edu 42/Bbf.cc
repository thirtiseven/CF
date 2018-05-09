#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, a, b;
	std::string s;
	std::cin >> n >> a >> b >> s;
	s += '#';
	int t = 0, tot = 0;
	int odd = 0;
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (s[i] == '.') {
			t++;
			tot++;
		} else {
			if (t%2==1) {
				if (a > b) {
					ans += std::min((t+1)/2, a);
					a -= std::min((t+1)/2, a);
					ans += std::min((t)/2, b);
					b -= std::min((t)/2, b);
				} else {
					ans += std::min((t)/2, a);
					a -= std::min((t)/2, a);
					ans += std::min((t+1)/2, b);
					b -= std::min((t+1)/2, b);
				}
			} else {
				ans += std::min((t)/2, a);
				a -= std::min((t)/2, a);
				ans += std::min((t)/2, b);
				b -= std::min((t)/2, b);
			}
			t=0;
		}
//		std::cout << a << " " << b << '\n';
	}
	std::cout << ans;
}