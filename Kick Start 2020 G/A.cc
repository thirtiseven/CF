#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;

ll t, n, d, c, m;
std::string s;
bool yes;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	int cnt = 1;
	while (t--) {
		std::cin >> n >> d >> c >> m;
		std::cin >> s;
		yes = 1;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'D') {
				d--;
				c += m;
			} else {
				c--;
			}
			if (d < 0) {
				yes = 0;
			}
			if (c < 0) {
				d = 0;
			}
		}
		if (yes) {
			std::cout << "Case #" << cnt << ": YES\n"; 
 		} else {
			std::cout << "Case #" << cnt << ": NO\n"; 
		}
		cnt++;
	}
}