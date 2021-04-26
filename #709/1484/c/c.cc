#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

const int maxn = 100007;

int t, n, m;
std::vector<int> f[maxn];
int ans[maxn];
std::map<int, int> mp;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		mp.clear();
		std::cin >> n >> m;
		for (int i = 0; i < m; i++) {
			f[i].clear();
			int k, temp;
			std::cin >> k;
			for (int j = 0; j < k; j++) {
				std::cin >> temp;
				f[i].emplace_back(temp);
			}
			std::sort(f[i].begin(), f[i].end());
//			std::cout << i << ' ' << f[i].size() << '\n';
		}
		for (int i = 0; i < m; i++) {
			ans[i] = f[i][0];
			mp[f[i][0]]++;
		}
		int label = -1, tot = 0;
		for (auto it: mp) {
			if (it.second > (m+1)/2) {
				label = it.first;
				tot = it.second;
//				std::cout << label << ' ' << tot << '\n';
				break;
			}
		}
		for (int i = 0; i < m; i++) {
			if (ans[i] == label && tot > (m+1)/2) {
				if (f[i].size() > 1) {
					ans[i] = f[i][1];
					tot--;
				}
			}
		}
//		std::cout << tot << ' ' << (m+1)/2 << '\n';
		if (tot > (m+1)/2) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
			for (int i = 0; i < m; i++) {
				std::cout << ans[i] << " \n"[i==m-1];
			}
		}
 	}
}