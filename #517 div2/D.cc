#include <iostream>
#include <string>
#include <cstring>

const int maxn = 2018;

std::string s[maxn];
int n, k;
int dp[maxn][maxn], v[maxn][maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + int(s[i-1][j-1]!='a');
			if (dp[i][j] <= k) {
				s[i-1][j-1] = 'a';
			}
		}
	}
//	for (int i = 0; i < n; i++) {
//		std::cout << s[i] << '\n';
//	}
	char cur = s[0][0];
	char minn = 'z';
	int now = 0;
	v[1][1] = 1;
	for (k = 2; k <= 2*n; k++) {
		char mn = 'z';
		int fr = std::max(1, k-n);
		for(int i = fr; i <= k-fr; i++) {
			if(v[i][k-i]) {
				mn = std::min(mn, s[i-1][k-i-1]);
			}
		}
		putchar(mn);
		for(int i=fr; i<=k-fr; i++) {
			if(v[i][k-i] && s[i-1][k-i-1]==mn) v[i][k-i+1] = v[i+1][k-i] = 1;
		}
	}
}