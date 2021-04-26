#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cassert>

const int maxn = 1e5+7;

int n, a[maxn];
std::vector<std::pair<int, int>> ans;
std::queue<int> one, two, there, notzero;
std::set<int> left;

void test() {
	std::cerr << "----\n";
	std::cerr << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		std::cerr << ans[i].first << ' ' << ans[i].second << '\n';
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if (a[i] != 0 && a[i] != 2) {
			notzero.push(i);
		}
		if (a[i] == 1) {
			one.push(i);
		}
	}
	bool yes = 1;
	int next = 1;
	bool first = 1;
	int x;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			if (notzero.empty() && first) {
				yes = 0;
				break;
			}
			if (first) {
				x = notzero.front();
				if (a[x] == 1) {
					one.pop();
				}
				notzero.pop();
				ans.push_back(std::make_pair(x, next));
				first = 0;
			}
			next++;
			if (!notzero.empty()) {
				x = notzero.front();
				if (next > n) {
					yes = 0;
					break;
				}
				ans.push_back(std::make_pair(x, next));
				if (a[x] == 1) {
					one.pop();
				}
				notzero.pop();
			}
		} else if (a[i] == 2) {
			if (one.empty()) {
				yes = 0;
				break;
			}
			ans.push_back(std::make_pair(i, next));
			x = one.front();
			if (next > n) {
				yes = 0;
				break;
			}
			ans.push_back(std::make_pair(x, next));
			next++;
			one.pop();
		} else if (a[i] == 3) {
			if (notzero.empty()) {
				yes = 0;
				break;
			}
			x = notzero.front();
			notzero.pop();
			ans.push_back(std::make_pair(x, next));
			x = notzero.front();
			if (next > n) {
				yes = 0;
				break;
			}
			ans.push_back(std::make_pair(x, next));
			next++;
			if (!notzero.empty()) {
				if (next > n) {
					yes = 0;
					break;
				}
				ans.push_back(std::make_pair(x, next));
				notzero.pop();
			}
		}
	}
	if (!yes) {
		std::cout << "-1\n";
		test();
		exit(0);
	}
	std::cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i].second << ' ' << ans[i].first << '\n';
	}	
}