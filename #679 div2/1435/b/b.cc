#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

const int maxn = 521;

int T, n, m, a[maxn][maxn], b[maxn][maxn];
std::map<int, std::vector<int>> mp;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		mp.clear();
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cin >> a[i][j];
				mp[a[i][0]].push_back(a[i][j]);
			}
		}
		int xx = -1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				std::cin >> b[i][j];
				if (b[i][j] == a[0][0]) {
					xx = i;
				}
			}
		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				std::cout << a[i][j] << ' ';
//			}
//			std::cout << '\n';
//		}
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				std::cout << b[i][j] << ' ';
//			}
//			std::cout << '\n';
//		}
		assert(xx >= 0);
//		std::cout << xx << "!!!\n";
		for (int i = 0; i < n; i++) {
			for (auto it: mp[b[xx][i]]) {
				std::cout << it << ' ';
			}
			std::cout << '\n';
		}
	}
}