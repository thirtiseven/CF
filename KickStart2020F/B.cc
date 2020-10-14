#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1e5+7;
int T, n, k, s, e;
std::vector<std::pair<int, int>> seg; 

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int _ = 1; _ <= T; _++) {
		seg.clear();
		std::cin >> n >> k;
		for (int i = 0; i < n; i++) {
			std::cin >> s >> e;
			seg.push_back(std::make_pair(s, e));
		}
		std::sort(seg.begin(), seg.end());
		int ans = 0, cur = -1;
		for (int i = 0; i < n; i++) {
//			std::cout << cur << ' ' << seg[i].first << ' ' << seg[i].second << '\n';
			if (cur <= seg[i].first) {
				cur = seg[i].first;
			} else if (cur >= seg[i].second) {
				continue;
			}
			ans += ((seg[i].second - cur - 1) / k + 1);
			cur += ((seg[i].second - cur - 1) / k + 1) * k;
		}
		std::cout << "Case #" << _ << ": " << ans << '\n';
	}
}