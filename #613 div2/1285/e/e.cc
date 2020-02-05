#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

const int maxn = 2e5+7;

int T;
int n;
std::pair<int, int> seg[maxn];
std::vector<std::pair<int, int>> point;
std::set<std::pair<int, int>> s;
std::map<std::pair<int, int>, int> id;

std::set<std::pair<int, int>>::iterator split1(int pos) {
	auto it = s.lower_bound(std::make_pair(pos, pos));
	--it;
	if (it->second <= pos) {
		++it;
	}
	return it;
}

std::set<std::pair<int, int>>::iterator split2(int pos) {
	auto it = s.upper_bound(std::make_pair(pos, pos));
	it--;
	return it;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		point.clear();
		s.clear();
		int zero = 1;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> seg[i].first >> seg[i].second;
			point.push_back(std::make_pair(seg[i].first, 1));
			point.push_back(std::make_pair(seg[i].second, 2));
		}
		std::sort(point.begin(), point.end());
		int cur = 0, pre = 0;
		if (point[0].second == 1) {
			pre = cur;
			cur++;
		} else {
			pre = cur;
			cur--;
		}
		for (int i = 1; i < point.size(); i++) {
			if (cur == 0 && point[i].first != point[i-1].first) {
				zero++;
			}
			if (cur == 1 && pre != 0 && point[i].second != 2 && point[i-1].first != point[i].first) {
				s.insert(std::make_pair(point[i-1].first, point[i].first));
			}
			if (point[i].second == 1) {
				pre = cur;
				cur++;
			} else {
				pre = cur;
				cur--;
			}
		}
		s.insert(std::make_pair(-1000000001, -1000000001));
		s.insert(std::make_pair(1000000001, 1000000001));
		int ans = 1;
		int cnt = 1;
		for (auto it: s) {
//			std::cout << it.first << ' ' << it.second << '\n';
			id[it] = cnt;
			cnt++;
		}
//		std::cout << zero << "!\n";
 		for (int i = 0; i < n; i++) {
			auto l = split1(seg[i].first);
			auto r = split2(seg[i].second);
			ans = std::max(ans, zero + std::max(id[*r]-id[*l]+1, 0));
		}
		if (s.size() == 2 && zero > 1) {
			ans = zero - 1;
		}
		std::cout << ans << '\n';
	}
}