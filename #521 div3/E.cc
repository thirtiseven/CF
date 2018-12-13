#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

const int maxn = 4e5+7;

std::map<int, int> mp;
int n;
std::vector<int> v;
int dp[maxn];

int main(int argc, char *argv[]) {  
	std::fill(dp, dp+maxn, 0);
	std::cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		mp[t]++;
	}
	for (auto it: mp) {
		v.push_back(it.second);
	}
	std::sort(v.begin(), v.end());
//	for (auto it: v) {
//		std::cerr << it << " ";
//	}
//	std::cerr << '\n';
	int ans = 0;
	for (int i = v.size()-1; i >= 0; i--) {
		for (int j = 1; j <= v[i]; j++) {
			dp[j] = std::max(dp[j], j+dp[2*j]);
			ans = std::max(ans, dp[j]);
		}
	}
	std::cout << ans << '\n';
}