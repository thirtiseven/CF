#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

const int maxn = 2e5+7;

int T;
std::string s;
std::vector<int> ans;
int vis[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		ans.clear();
		std::cin >> s;
		int len = s.length();
		std::fill(vis, vis+len, 0);
		for (int i = 0; i < len-2; i++) {
			if (i < len-4 && s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e' && vis[i] == 0 && vis[i+1] == 0 && vis[i+2] == 0 && vis[i+3] == 0 && vis[i+4] == 0) {
				ans.push_back(i+2);
				vis[i+2] = 1;
			} if (s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e' && vis[i] == 0 && vis[i+1] == 0 && vis[i+2] == 0) {
				ans.push_back(i+1);
				vis[i+1] = 1;
			} else if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && vis[i] == 0 && vis[i+1] == 0 && vis[i+2] == 0) {
				ans.push_back(i+1);
				vis[i+1] = 1;
			}
		}
		std::cout << ans.size() << '\n';
		for (auto it: ans) {
			std::cout << it+1 << ' ';
		}
		std::cout << '\n';
	}
}