#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

const int maxn = 52;

int T, n;
std::string s;
int ans[maxn][maxn];
std::vector<int> two;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> s;
		two.clear();
		for (int i = 0; i < n; i++) {
			if (s[i] == '2') {
				two.emplace_back(i);
			}
		}
		if (two.size() == 1 || two.size() == 2) {
			std::cout << "NO\n";
			continue;
		}
		std::cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans[i][j] = 3;
				if (i == j) {
					ans[i][j] = 4;
				}
			}
		}
		for (int i = 0; i < two.size(); i++) {
			int a = two[i];
			int b = two[(i+1)%two.size()];
			ans[a][b] = 1;
			ans[b][a] = 2;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ans[i][j] == 1) {
					std::cout << '+';
				} else if (ans[i][j] == 2) {
					std::cout << '-';
				} else if (ans[i][j] == 3) {
					std::cout << '=';
				} else {
					std::cout << 'X';
				}
			}
			std::cout << '\n';
		}
	}
}