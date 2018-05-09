#include <iostream>
#include <vector>
#include <list>
#include <cstring>

using ll = long long;
std::list<ll> ans;

int main(int argc, char *argv[]) {  
	ll n, a[123];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	ans.push_back(a[0]);
	int vis[123];
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[j] == 0) {
				if (a[j] == 3* ans.front()) {
					ans.push_front(a[j]);
				} else if (a[j] == 2 * ans.back()) {
					ans.push_back(a[j]);
				} else if (2*a[j] == ans.front()) {
					ans.push_front(a[j]);
				} else if (3*a[j] == ans.back()) {
					ans.push_back(a[j]);
				}
			}
		}
	}
	for (auto i: ans) {
		std::cout << i << " ";
	}
}