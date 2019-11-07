#include <iostream>
#include <algorithm>

const int maxn = 5008;
using ll = long long;

std::pair<ll, ll> c[maxn];
int vis[maxn];

bool cmp(std::pair<ll, ll> a, std::pair<ll, ll> b) {
	return a.second < b.second;
}

int main(int argc, char *argv[]) {  
	ll T;
	std::cin >> T;
	int n;
	while (T--) {
		std::cin >> n;
		for (ll i = 0; i < n; i++) {
			std::cin >> c[i].first >> c[i].second;
		}
		std::sort(c, c+n, cmp);
		int now = 0, cost = 0;
		std::fill(vis, vis+n, 0);
		for (int i = 0; i < n; i++) {	
			for (int j = 0; j < n; j++) {
				if (!vis[j] && c[j].first <= now) {
					vis[j] = 1;
					now++;
				}
			}
			if (i == now) {
				for (int j = 0; j < n; j++) {
					if (!vis[j]) {
						cost += c[j].second;
						vis[j] = 1;
						break;
					}
				}
			}
		}
		std::cout << cost << '\n';
	}
}