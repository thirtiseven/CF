#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

std::stack<int> p[28];
std::vector<std::pair<int, int>> ans;
int vis[150007];

int main(int argc, char *argv[]) {
	std::fill(vis, vis+150007, 0);
	int n;
	std::cin >> n;
	std::string s1, s2;
	std::cin >> s1 >> s2;
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == '?') {
			p[26].push(i+1);
		} else {
			p[int(s2[i]-'a')].push(i+1);
		}
	}
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '?') {
			p[27].push(i+1);
			continue;
		}
		if (!p[int(s1[i]-'a')].empty()) {
			ans.push_back(std::make_pair(i+1, p[int(s1[i]-'a')].top()));
			vis[p[int(s1[i]-'a')].top()-1] = 1;
			p[int(s1[i]-'a')].pop();			
		} else if (!p[26].empty()) {
			ans.push_back(std::make_pair(i+1, p[26].top()));
			vis[p[26].top()-1] = 1;
			p[26].pop();
		}
	}
	for (int i = 0; i < n; i++) {
		if (p[27].empty()) {
			break;
		}
		if (!vis[i]) {
			ans.push_back(std::make_pair(p[27].top(), i+1));
			p[27].pop();
		}
	}
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << it.first << " " << it.second << '\n';
	}
}