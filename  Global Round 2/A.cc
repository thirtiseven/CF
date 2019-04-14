#include <iostream>
#include <set>
#include <algorithm>

const int maxn = 300003;

int n, c[maxn], minn[maxn], maxx[maxn];
std::set<int> s;

int main(int argc, char *argv[]) {  
	std::fill(minn, minn+maxn, maxn);
	std::fill(maxx, maxx+maxn, 0);
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
		maxx[c[i]] = std::max(maxx[c[i]], i);
		minn[c[i]] = std::min(minn[c[i]], i);
		s.insert(c[i]);
	}
	int ans = 0;
	for (auto it: s) {
		if (it != c[1]) {
			ans = std::max(maxx[it]-1, ans);
		}
		if (it != c[n]) {
			ans = std::max(n-minn[it], ans);
		}
	}
	std::cout << ans << '\n';
}