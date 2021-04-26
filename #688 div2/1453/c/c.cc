#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 2020;

int T, n, ans[10];
std::string s[maxn];
int l[maxn][10], r[maxn][10], u[maxn][10], d[maxn][10];
int lk[10], rk[10], uk[10], dk[10];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
		}
		for (int i = 0; i < 10; i++) {
			lk[i] = uk[i] = maxn;
			rk[i] = dk[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < 10; k++) {
				l[i][k] = maxn;
				r[i][k] = -1;
				u[i][k] = maxn;
				d[i][k] = -1;
			}
		}
		std::fill(ans, ans+10, 0);
		for (int k = 0; k < 10; k++) {
			for (int i = 0; i < n; i++) {
				bool once = 0;
				for (int j = 0; j < n; j++) {
					if (s[i][j] == '0'+k) {
						once = 1;
						lk[k] = std::min(j, lk[k]);
						rk[k] = std::max(j, rk[k]);
						uk[k] = std::min(i, uk[k]);
						dk[k] = std::max(i, dk[k]); 
						l[i][k] = std::min(l[i][k], j);
						r[i][k] = std::max(r[i][k], j);	
					}
				}
				if (once) {
					ans[k] = std::max(ans[k], (r[i][k]-l[i][k])*(std::max(i-0, n-1-i)));
				}
			}
		}
		for (int k = 0; k < 10; k++) {
			for (int j = 0; j < n; j++) {
				bool once = 0;
				for (int i = 0; i < n; i++) {
					if (s[i][j] == '0'+k) {
						once = 1;
						u[j][k] = std::min(u[j][k], i);
						d[j][k] = std::max(d[j][k], i);	
					}
				}
				if (once) {
					ans[k] = std::max(ans[k], (d[j][k]-u[j][k])*(std::max(j-0, n-1-j)));
				}
			}
		}
		for (int k = 0; k < 10; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if ((j - u[i][k]) > 0 && (i - lk[k] > 0))
						ans[k] = std::max(ans[k], (j - u[i][k])*(i - lk[k]));
					if ((j - u[i][k]) > 0 && ((rk[k] - i) > 0))
						ans[k] = std::max(ans[k], (j - u[i][k])*(rk[k] - i));
					if (d[i][k] - j > 0 && (i - lk[k] > 0))
						ans[k] = std::max(ans[k], (d[i][k] - j)*(i - lk[k]));
					if (d[i][k] - j > 0 && rk[k] - i > 0)
						ans[k] = std::max(ans[k], (d[i][k] - j)*(rk[k] - i));
					if ((j - uk[k]) > 0 && (i - l[j][k] > 0))
						ans[k] = std::max(ans[k], (j - uk[k])*(i - l[j][k]));
					if ((j - uk[k]) > 0 && ((r[j][k] - i) > 0))
						ans[k] = std::max(ans[k], (j - uk[k])*(r[j][k] - i));
					if (dk[k] - j > 0 && (i - l[j][k] > 0))
						ans[k] = std::max(ans[k], (dk[k] - j)*(i - l[j][k]));
					if (dk[k] - j > 0 && r[j][k] - i > 0)
						ans[k] = std::max(ans[k], (dk[k] - j)*(r[j][k] - i));
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			std::cout << ans[i] << ' ';
		}
		std::cout << '\n';
	}
}