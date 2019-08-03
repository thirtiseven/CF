#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

const int maxn = 2e5+7;

int T, n, k;
std::string s;
int R[3][maxn], G[3][maxn], B[3][maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		memset(R, sizeof(R), 0);
		memset(G, sizeof(G), 0);
		memset(B, sizeof(B), 0);
		std::cin >> n >> k >> s;
		for (int i = 0; i < n; i++) {
			int r = 0, g = 0, b = 0;
			if (s[i] == 'R') {
				r++;
			} else if (s[i] == 'G') {
				g++;
			} else {
				b++;
			}
			R[i%3][i+1] = R[i%3][i] + r;
			G[i%3][i+1] = G[i%3][i] + g;
			B[i%3][i+1] = B[i%3][i] + b;
			R[(i+1)%3][i+1] = R[(i+1)%3][i];
			G[(i+1)%3][i+1] = G[(i+1)%3][i];
			B[(i+1)%3][i+1] = B[(i+1)%3][i];
			R[(i+2)%3][i+1] = R[(i+2)%3][i];
			G[(i+2)%3][i+1] = G[(i+2)%3][i];
			B[(i+2)%3][i+1] = B[(i+2)%3][i];
		}
		int ans = maxn;
		for (int i = 0; i+k <= n; i++) {
			for (int j = 0; j < 3; j++) {
				int cur = k;
				cur -= (R[j][i+k] - R[j][i]);
				cur -= (G[(j+1)%3][i+k] - G[(j+1)%3][i]);
				cur -= (B[(j+2)%3][i+k] - B[(j+2)%3][i]);
				ans = std::min(cur, ans);
			}
		}
		std::cout << ans << '\n';
	}
}