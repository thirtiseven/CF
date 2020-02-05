#include <iostream>
#include <string>

const int maxn = 1e5+7;

int T;
std::string s;
int n, x;
int xx[maxn];
int c;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> x >> s;
		xx[0] = 0;
		for (int i = 0; i < n; i++) {
			xx[i+1] = xx[i];
			if (s[i] == '0') {
				xx[i+1]++;
			} else {
				xx[i+1]--;
			}
		}
		int c = xx[n];
		if (c == 0) {
			int ans = 0;
			for (int i = 0; i < n; i++) {
				if (xx[i] == x) {
					ans = -1;
				}
			}
			std::cout << ans << "\n";
			continue;
		}
		int ans = 0 + int(x==0);
		for (int i = 1; i <= n; i++) {
			if ((x-xx[i])%c==0 && (x-xx[i])/c>=0) {
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}