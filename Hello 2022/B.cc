#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

const int maxn = 1e5+7;

int t;
int n;
int l[maxn], r[maxn], c[maxn];
std::map<int, int> mpl, mpr;
std::vector<int> ans;
std::pair<int, int> lr;
int lrc;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		mpl.clear();
		mpr.clear();
		ans.clear();
		std::cin >> n;
		lr = std::make_pair(0, 0);
		lrc = INT_MAX;
		for (int i = 0; i < n; i++) {
			std::cin >> l[i] >> r[i] >> c[i];
			if (mpl.find(l[i]) != mpl.end()) mpl[l[i]] = std::min(mpl[l[i]], c[i]);
			else mpl[l[i]] = c[i];
			if (mpr.find(r[i]) != mpr.end()) mpr[r[i]] = std::min(mpr[r[i]], c[i]);
			else mpr[r[i]] = c[i];
			int cur = mpl.begin()->second + mpr.rbegin()->second;
			if (l[i] == mpl.begin()->first && r[i] == mpr.rbegin()->first) {
				if (lr.first == l[i] && lr.second == r[i]) {
					lrc = std::min(lrc, c[i]);
				} else {
					lrc = c[i];
				}
				lr = std::make_pair(l[i], r[i]);
			}
			if (lr.first == mpl.begin()->first && lr.second == mpr.rbegin()->first) {
				cur = std::min(lrc, cur);
			}
			ans.push_back(cur);
//			std::cerr << "-------------\n";
//			std::cerr << mpl.begin()->first << ' ' << mpl.begin()->second << ' ' << mpr.rbegin()->first << ' ' << mpr.rbegin()->second << '\n';
//			std::cerr << lr.first << ' ' << lr.second << ' ' << lrc << '\n';
//			std::cerr << "-------------\n";
		}
		for (auto it: ans) {
			std::cout << it << '\n';
		}
	}
}