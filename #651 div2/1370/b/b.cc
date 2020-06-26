#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 2004;

int T, n, a[maxn];
std::vector<int> odd, eve;
std::vector<std::pair<int, int>> ans;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		odd.clear();
		eve.clear();
		ans.clear();
		std::cin >> n;
		for (int i = 1; i <= n*2; i++) {
			std::cin >> a[i];
			if (a[i] % 2 == 0) {
				eve.push_back(i);
			} else {
				odd.push_back(i);
			}
		}
		for (int i = 0; i < odd.size()/2; i++) {
			ans.push_back(std::make_pair(odd[i*2], odd[i*2+1]));
		}
		for (int i = 0; i < eve.size()/2; i++) {
			ans.push_back(std::make_pair(eve[i*2], eve[i*2+1]));
		}
		for (int i = 0; i < n-1; i++) {
			std::cout << ans[i].first << ' ' << ans[i].second << '\n';
		}
	}
}