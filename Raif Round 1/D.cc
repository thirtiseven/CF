#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cassert>

const int maxn = 1e5+7;

int n, a[maxn];
std::vector<std::pair<int, int>> ans;
std::queue<int> one, two, there;
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
		if (a[i] == 1) {
			two.push(i);
		}
		if (a[i] == 3) {
			there.push(i);
		}
	}
	bool yes = 1;
	int next = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 2) {
			if (next > n) {
				yes = 0;
				break;
			}
			ans.push_back(std::make_pair(i, next));
			int x;
			if (two.empty() && one.empty()) {
				yes = 0;
				break;
			}
			if (!one.empty()) {
				x = one.front();
				one.pop();
				ans.push_back(std::make_pair(x, next));
			} else {
				x = two.front();
				one.push(x);
				two.pop();
				ans.push_back(std::make_pair(x, next));
			}
			next++;
		} else if (a[i] == 3) {
			if (next > n) {
				yes = 0;
				break;
			}
			assert(i == there.front());
			there.pop();
			ans.push_back(std::make_pair(i, next));
			int x;
			if (!there.empty()) {
				x = there.front();
				left.insert(x);
				there.pop();
				ans.push_back(std::make_pair(x, next));
				next++;
			}
			if (two.empty()) {
				yes = 0;
				break;
			}
			x = two.front();
			left.insert(x);
			two.pop();
			ans.push_back(std::make_pair(x, next));
			next++;
		}
	}
	if (!yes) {
		std::cout << "-1\n";
		test();
		exit(0);
	}
	while (!two.empty()) {
		left.insert(two.front());
		two.pop();
	}
	for (auto it: left) {
		if (next > n) {
			yes = 0;
			break;
		}
		ans.push_back(std::make_pair(it, next));
		next++;
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