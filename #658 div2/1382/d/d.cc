#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 2007;

int T, n, p[maxn*2];
int w[maxn], v[maxn];
int W;
int dp[maxn];

void ZOP(int weight, int value) {
	for(int i = W; i >= weight; i--) {
		dp[i]=std::max(dp[i],dp[i-weight]+value);
	}
}


int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::vector<int> seg;
		std::cin >> n;
		for (int i = 0; i < 2*n; i++) {
			std::cin >> p[i];
		} 
		int cur = 1, now = p[0];
		for (int i = 1; i < 2*n; i++) {
			if (p[i] < now) {
				cur++;
			} else {
				seg.push_back(cur);
				now = p[i];
				cur = 1;
			}
		} 
		seg.push_back(cur);
//		for (auto it: seg) {
//			std::cout << it << ' ';
//		}
		std::fill(dp, dp+maxn, -1000000);
		dp[0] = 0;
		W = n;
		for (auto it: seg) {
			ZOP(it, 1);
		}
		if (dp[W] > 0) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}