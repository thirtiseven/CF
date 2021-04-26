#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1e5+7;

int n, p[maxn];
std::vector<int> seg;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	int cur = 1;
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	bool up = 1;
	for (int i = 1; i < n; i++) {
		if (p[i] > p[i-1]) {
			if (up) {
				cur++;
			} else {
				cur++;
				if (cur > 1) {
					seg.push_back(cur);
					cur = 1;
				}
				up = 0;
			}
		} else {
			if (down) {
				cur++;
			} else {
				cur++;
				if (cur > 1) {
					seg.push_back(cur);
					cur = 1;
				}
				up = 1;
			}
		}
	}
	if (cur > 1) {
		seg.push_back(cur);
	}
	std::sort(seg.begin(), seg.end());
	int ans = 0;
	if (*seg.rbegin() % 2 == 1) {
		ans++;
	}
}