#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

const int maxn = 207;

int t, n, k[maxn], temp, ocr[maxn];
std::vector<int> p[maxn], ans;
std::set<int> num[maxn];
std::set<int> just;

void init() {
//	std::fill(ocr, ocr+n+1, 0);
	for (int i = 1; i <= n; i++) {
		p[i].clear();
		num[i].clear();
	}
	ans.clear();
	just.clear();
}

int findOne() {
//	std::cout << "! ";
	std::vector<int> xx;
	for (int i = 1; i <= n; i++) {
		if (num[i].size() == 1) {
			xx.push_back(i);
		}
	}
	if (xx.size() == 2) {
//		std::cout << xx[0] << ' ' << xx[1] << '\n'; 
		if (just.empty() || just.find(xx[0]) != just.end()) {
			ans.push_back(xx[0]);
			if (ans.size() == n-1) {
				ans.push_back(xx[1]);
			}
			return *num[xx[0]].begin();
		} else {
			ans.push_back(xx[1]);
			if (ans.size() == n-1) {
				ans.push_back(xx[0]);
			}
			return *num[xx[1]].begin();
		}
	} else {
//		std::cout << xx[0] << '\n';
		ans.push_back(xx[0]);
	}
	return *num[xx[0]].begin();
}

void eraseX(int x) {
//	std::cout << "Erase " << x << '\n';
	for (int i = 1; i <= n; i++) {
		if (num[i].find(x) != num[i].end()) {
			num[i].erase(x);
			just.insert(i);
		}
	}
//	std::cout << "Erase done.\n";
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		init();
		for (int i = 1; i <= n-1; i++) {
			std::cin >> k[i];
			for (int j = 0; j < k[i]; j++) {
				std::cin >> temp;
				p[i].push_back(temp);
				num[temp].insert(i);
//				ocr[temp]++;
			}
		}
		for (int i = 0; i < n-1; i++) {
			int x = findOne();
			just.clear();
			eraseX(x);
		}
//		std::cout << "!!!!\n";
		std::reverse(ans.begin(), ans.end());
		for (auto it: ans) {
			std::cout << it << ' ';
		}
		std::cout << '\n';
	}
}