#include <iostream>
#include <algorithm>

const int maxn = 2e5+6;

int p[maxn], q, n, h;

int main(int argc, char *argv[]) {  
	std::cin >> q;
	while (q--) {
//		std::fill(num, num+maxn, 0);
		std::cin >> h >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> p[i];
		}
		p[n] = 0;
		int ans = 0;
		for (int i = 0; i < n-2;) {
			if (p[i+1] == p[i]-1) {
				if (p[i+2] != p[i]-2) {
					ans++;
				}
				i+=2;
			} else {
				i++;
			}
		}
		std::cout << ans << '\n';
	}
}