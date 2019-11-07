#include <iostream>
#include <algorithm>

const int maxn = 2003;
using ll = long long;

struct point {
	ll x, y, z;
};

point p[maxn];
int vis[maxn];

ll dis(int a, int b) {
	return (p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y)+(p[a].z-p[b].z)*(p[a].z-p[b].z);
}

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i].x >> p[i].y >> p[i].z;
	}
	std::fill(vis, vis+maxn, 0);
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			continue;
		}
		ll minn = 2e18;
		int cur = 0;
		ll temp;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && j != i) {
				temp = dis(i, j);
				if (temp < minn) {
					minn = temp;
					cur = j;
				}
			}
		}
		std::cout << i << ' ' << cur << '\n';
		vis[cur] = 1;
		vis[i] = 1;
	}
}