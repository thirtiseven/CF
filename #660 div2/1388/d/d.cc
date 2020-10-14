#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 2e5+7;
using ll = long long;
int n;
ll a[maxn], ans;
int b[maxn];
std::vector<int> t[maxn];
int depth[maxn];
std::pair<int, int> depth_point[maxn];
std::vector<int> res, buf;

void getdep(int root, int dep) {
	depth[root] = dep;
	for (auto it: t[root]) {
		getdep(it, dep+1);
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		if (b[i] != -1) {
			t[b[i]].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] == -1) {
			getdep(i, 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		depth_point[i] = std::make_pair(depth[i], i);
	}
	std::sort(depth_point+1, depth_point+n+1);
	std::reverse(depth_point+1, depth_point+n+1);
	ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = depth_point[i].second;
		if (a[x] >= 0) {
			ans += a[x];
			res.push_back(x);
			if (b[x] != -1) {
				a[b[x]] += a[x];
			}
		} else {
			buf.push_back(x);
		}
	}
	std::reverse(buf.begin(), buf.end());
	for (auto it: buf) {
		ans += a[it];
		res.push_back(it);
	}
	std::cout << ans << '\n';
	for (auto it: res) {
		std::cout << it << " ";
	}
}

