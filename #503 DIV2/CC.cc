#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using ll = long long;

int main(int argc, char *argv[]) {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> p(n), c(n);
	for (int i=0; i<n; ++i)
		std::cin >> p[i] >> c[i];
	std::vector<std::vector<ll> > v(m);
	for (int i=0; i<n; ++i)
		v[p[i]-1].push_back(c[i]);
	for (int i=0; i<m; ++i)
		std::sort(v[i].begin(), v[i].end());
	ll best = 10000000000000LL;
	for (int votes=1; votes<=n; ++votes) {
		ll bribe=0;
		int curvotes = v[0].size();
		std::vector<ll> extra;
		for (int i=1; i<m; ++i) {
			for (int j=0; j<(int)(v[i].size())-votes+1; ++j) {
				bribe += v[i][j];
				curvotes++;
			}
			for (int j=std::max(0,(int)(v[i].size())-votes+1); j<v[i].size(); ++j)
				extra.push_back(v[i][j]);
		}
		sort(extra.begin(), extra.end());
		for (int i=0; i<votes-curvotes; ++i)
			bribe += extra[i];
		best = std::min(best, bribe);
	}
	std::cout << best << std::endl;
}