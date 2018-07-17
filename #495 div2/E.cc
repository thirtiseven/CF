#include <iostream>
#include <set>
#include <algorithm>

#define pii	std::pair<int,int>
#define mp	std::make_pair

const int maxn = 1e5+7;

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::set<pii> t[maxn], s;
	std::cin >> n >> k;
	int u,v,w;
	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		std::cin >> u >> v >> w;
		t[u].insert(mp(v, w));
		t[v].insert(mp(u, w));
	}
	for (int i = 1; i <= n; i++) {
		if (t[i].size() == 1) {
			s.insert(mp((*t[i].begin()).second, i));
		}
	}
	while (n>k && s.size()>2) {
		auto i = *s.begin();
		s.erase(i);
		int cur = i.second;
		ans = i.first;
		n--;
		int nxt = (*t[cur].begin()).first;
		t[nxt].erase(t[nxt].lower_bound(mp(cur, 0)));
		if (t[nxt].size() == 1) {
			s.insert(mp((*t[nxt].begin()).second+ans, nxt));
		}
	}
	std::cout << ans << std::endl;
}