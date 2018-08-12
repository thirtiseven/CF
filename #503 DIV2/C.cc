#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

const int maxn = 3009;

using ll = long long;

std::vector<ll> p[maxn], all;
int vis[maxn];

int main(int argc, char *argv[]) { 
	std::fill(vis, vis+maxn, 0); 
	int n, m;
	int t1; 
	long long t2;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> t1 >> t2;
		p[t1].push_back(t2);
		if (t1 != 1) all.push_back(t2);
		vis[t1] = 1;
	}
	int maxsize = 0;
	for (int i = 1; i <= m; i++) {
		if (!vis[i]) continue;
		maxsize = std::max(maxsize, int(p[i].size()));
	}
	maxsize = std::min(maxsize+1, n);
	long long ans = 1e16;
	for (int need = n/m; need <= maxsize; need++) {
		std::vector<ll> miu;
		int add = 0;
		ll cost = 0;
		for (int j = 2; j <= m; j++) {
			if (!vis[j]) continue;
			if (p[j].size() >= need) {
				std::sort(p[j].begin(), p[j].end());
				for (int h = 0; h < (p[j].size()-need+1); h++) {
					miu.push_back(p[j][h]);
					cost += p[j][h];
					add++;
				}
			}
		}
		int now;
		if (!vis[1]) {
			now = add;
		} else {
			now = p[1].size()+add;
		}
//		std::cout << now << " " << cost << '\n';
		if (now < need) {
			std::sort(all.begin(), all.end());
			int lab = 0;
			for (ll it: all) {
				if (now >= need) break;
				cost += it;
				now ++;
				if (lab < miu.size() && it == miu[lab]) {
					cost -= it;
					lab ++;
					now --;
				}
//				std::cout << now << " " << cost << '\n';
			}
		}
		if (now>=need) {
			ans = std::min(ans, cost);
		}
//		std::cout << ">>>" <<need << " " << cost << '\n';
	}
	std::cout << ans << '\n';
}
