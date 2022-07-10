#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

//i / a[i] == b[i]
//i / b[i] == a[i]

const int maxn = 5e5+7;

using ll = long long;

ll t, n, b[maxn], a[maxn];

std::vector<std::pair<ll, ll>> x[maxn];

void iv(ll bb, ll i) {
	x[i/(bb+1)+1].emplace_back((bb==0 ? n : i/bb),i);
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		for (int i = 0; i <= n; i++) {
			x[i].clear();
		}
		std::cin >> n;
		for (ll i = 1; i <= n; i++) {
			std::cin >> b[i];
			iv(b[i], i);
		}
		std::priority_queue<std::pair<int,int>> q;
		for (int i=1; i<=n; i++) {
				for(auto& ed : x[i]) {
					q.push({-ed.first,ed.second});
				}
				assert(!q.empty());
				a[q.top().second]=i;
				q.pop();
			}
		for (ll i = 1; i <= n; i++) {
			std::cout << a[i] << ' ';
		}
		std::cout << '\n';
	}
}