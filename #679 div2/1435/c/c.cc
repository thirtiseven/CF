#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

const int maxn = 100007;
int a[7], n, b[maxn];
std::vector<std::pair<int, int>> x;
std::queue<int> v[maxn];
std::map<int, int> now;
int cnt[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	for (int i = 0; i < 6; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+6);
	std::cin >> n;
	int ans = 1e9, minn = 1e9, maxx = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
		minn = std::min(b[i]-a[0], minn);
		now[b[i]-a[0]]++;
		for (int j = 0; j < 6; j++) {
			v[i].push(b[i] - a[j]);
			x.push_back(std::make_pair(b[i] - a[j], i));
		}
	}
	std::sort(x.begin(), x.end());
	std::reverse(x.begin(), x.end());
	for (int i = 0; i < 5*n; i++) {
		auto it = now.end();
		it--;
//		std::cout << x[i].first << ' ' << x[i].second << ' ' << it->first << ' ' << now.begin()->first << '\n';
		ans = std::min(ans, it->first-now.begin()->first);
		if (v[x[i].second].size() > 1) {
			now[x[i].first]--;
			if (now[x[i].first] == 0) {
				now.erase(x[i].first);
			}
			v[x[i].second].pop();
			now[v[x[i].second].front()]++;
		}
	}
	std::cout << ans << '\n';
}