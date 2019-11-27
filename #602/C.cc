#include <iostream>
#include <string>
#include <vector>

int T;
std::string s;
int n, k;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n >> k;
		std::cin >> s;
		std::string ans = "";
		for (int i = 0; i < k-1; i++) {
			ans += "()";
		}
		for (int i = 0; i < (n/2)-(k-1); i++) {
			ans += "(";
		}
		for (int i = 0; i < (n/2)-(k-1); i++) {
			ans += ")";
		}
		std::vector<std::pair<int, int>> res;
		for (int i = 0; i < n; i++) {
			if (s[i] != ans[i]) {
				int xx = 0;
				for (int j = i+1; j < n; j++) {
					if (s[i] != s[j]) {
						xx = j;
						std::reverse(s.begin()+i, s.begin()+j);
						break;
					}
				}
				res.push_back(std::make_pair(i+1, xx+1));
			}
		}
		std::cout << res.size() << '\n';
		for (auto it: res) {
			std::cout << it.first << ' ' << it.second << '\n';
		}
	}
}