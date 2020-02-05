#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

const int maxn = 1e5+7;

int T, n;

std::map<std::pair<int, int>, std::vector<int>> m;
std::vector<int> round[maxn];
std::vector<int> s[maxn];
std::vector<int> ans1, ans2;

void init() {
	m.clear();
	for (int i = 0; i <= n; i++) {
		round[i].clear();
		s[i].clear();
	}
	ans1.clear();
	ans2.clear();
}

void dfs1(int now, int fa) {
	if (ans1.size() >= n) {
		return;
	}
	ans1.push_back(now);
	for (auto it: round[now]) {
		if (it != fa) {
			dfs1(it, now);
			break;
		}
	}
}

void dfs2(int now, int fa) {
	ans2.push_back(now);
	for (auto it: s[now]) {
		if (it != fa) {
			dfs2(it, now);
		}
	}
}

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);  
	std::cin >> T;
	int c[4];
	while (T--) {
		std::cin >> n;
		init();
		for (int i = 1; i <= n-2; i++) {
			std::cin >> c[0] >> c[1] >> c[2];
			std::sort(c, c+3);
			m[std::make_pair(c[0], c[1])].push_back(i);
			m[std::make_pair(c[0], c[2])].push_back(i);
			m[std::make_pair(c[1], c[2])].push_back(i);
		}
		for (auto it: m) {
			if (it.second.size() == 1) {
				round[it.first.first].push_back(it.first.second);
				round[it.first.second].push_back(it.first.first);
			} else if (it.second.size() == 2) {
//				std::cout << it.second[0] << ' ' << it.second[1] << '\n';
				s[it.second[0]].push_back(it.second[1]);
				s[it.second[1]].push_back(it.second[0]);
			}
		}
		dfs1(1, 0);
		dfs2(1, 0);
		std::reverse(ans2.begin(), ans2.end());
		for (auto it: ans1) {
			std::cout << it << ' ';
		}
		std::cout << '\n';
		for (auto it: ans2) {
			std::cout << it << ' ';
		}
		std::cout << '\n';
	}	
}