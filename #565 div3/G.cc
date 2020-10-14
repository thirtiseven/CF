#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 2e5+7;
int T, n, a[2][maxn];
std::vector<std::pair<int, int>> v[maxn];
int flip[maxn], vis[maxn];

void init() {
	for (int i = 0; i <= n; i++) {
		v[i].clear();
	}
	std::fill(flip, flip+n+1, 0);
	std::fill(vis, vis+n+1, 0);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		bool yes = 1;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[0][i];
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> a[1][i];
		}
//		std::cerr s<< "?????????\n";
		init();
		for (int i = 1; i <= n; i++) {
			if (a[0][i] > n) {
				yes = 0;
				break;
			}
			v[a[0][i]].push_back(std::make_pair(i, 0));
		}
		for (int i = 1; i <= n; i++) {
			if (a[1][i] > n) {
				yes = 0;
				break;
			}
			v[a[1][i]].push_back(std::make_pair(i, 1));
		}
		for (int i = 1; i <= n; i++) {
//			std::cerr << v[i].size() << " \n"[i==n];
			if (v[i].size() != 2) {
				yes = 0;
				break;
			}
		}
		if (yes == 0) {
			std::cout << "-1\n";
			continue;
		}
//		std::cerr << "----------\n";
		for (int i = 1; i <= n; i++) {
//			std::cerr << i << ' ' << v[i][0].second << ' ' << v[i][1].second << '\n';
			if (v[i][0].second == v[i][1].second) {
				if (vis[v[i][0].first] == 0) {
					flip[v[i][0].first] = 1;
					v[i][0].second = 1 - v[i][0].second;
					int num = 0;
//					std::cerr << v[i][0].first << ' ' << v[i][0].second << ' ' << a[v[i][0].second][v[i][0].first] << '\n';
					if (v[a[v[i][0].second][v[i][0].first]][0].first != v[i][0].first) {
						num = 1;
					}
//					std::cerr << num << '\n';
					v[a[v[i][0].second][v[i][0].first]][num].second = 1 - v[a[v[i][0].second][v[i][0].first]][num].second;
				} else {
					flip[v[i][1].first] = 1;
					v[i][1].second = 1 - v[i][1].second;
					int num = 0;
//					std::cerr << a[v[i][1].first][v[i][1].second] << '\n';
					if (v[a[v[i][1].second][v[i][1].first]][0].first != v[i][0].first) {
						num = 1;
					}
//					std::cerr << num << '\n';
					v[a[v[i][1].second][v[i][1].first]][num].second = 1 - v[a[v[i][1].second][v[i][1].first]][num].second;
				}
			}
			vis[v[i][0].first] = 1;
			vis[v[i][1].first] = 1;
		}
		int tot = 0;
		for (int i = 1; i <= n; i++) {
			tot += flip[i];
		}
		if (tot > n / 2) {
			std::cout << n-tot << '\n';
			for (int i = 1; i <= n; i++) {
				if (flip[i] == 0) {
					std::cout << i << ' ';
				}
			}
			std::cout << '\n';
		} else {
			std::cout << tot << '\n';
			for (int i = 1; i <= n; i++) {
				if (flip[i] == 1) {
					std::cout << i << ' ';
				}
			}
			std::cout << '\n';
		}
	}
}