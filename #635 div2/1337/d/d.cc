#include <iostream>
#include <algorithm>
#include <climits>

using ll = long long;
const int maxn = 1e5+7;

ll t, nr, ng, nb, r[maxn], g[maxn], b[maxn];

int minrgb(int x, int y, int z) {
	if (x == nr-1 && y == ng-1) {
//		std::cerr << "1:";
		return 2;
 	}
	if (z == nb-1 && y == ng-1) {
//		std::cerr << "2:";
		return 0;
 	}
	if (x == nr-1 && z == nb-1) {
//		std::cerr << "3:";
		return 1;
 	}
 	if (x == nr-1) {
//		std::cerr << "4:";
		return (g[y+1] <= b[z+1]? 1: 2);
	}
	if (y == ng-1) {
//		std::cerr << "5:";
		return (r[x+1] <= b[z+1]? 0: 2);
	}
	if (z == nb-1) {
//		std::cerr << "6:";
		return (r[x+1] <= g[y+1]? 0: 1);
	}	
	if (r[x+1] <= g[y+1] && r[x+1] <= b[z+1]) {
//		std::cerr << "7:";
		return 0;
	}
	if (g[y+1] <= r[x+1] && g[y+1] <= b[z+1]) {
//		std::cerr << "8:";
		return 1;
	}
//	std::cerr << "9:";
	return 2;	
}

ll gao(ll x, ll y, ll z) {
	return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> nr >> ng >> nb;
		for (int i = 0; i < nr; i++) {
			std::cin >> r[i];
		}
		for (int i = 0; i < ng; i++) {
			std::cin >> g[i];
		}
		for (int i = 0; i < nb; i++) {
			std::cin >> b[i];
		}
		std::sort(r, r+nr);
		std::sort(g, g+ng);
		std::sort(b, b+nb);
		ll ans = LLONG_MAX;
		int pos[3] = {0, 0, 0};
//		std::cout << gao(1111, 1112, 1113) << ' ' << gao(1112, 1112, 1114) << '\n';
		while (1) {
//			std::cout << pos[0] << ' ' << pos[1] << ' ' << pos[2] << '\n';
			ans = std::min(ans, gao(r[pos[0]], g[pos[1]], b[pos[2]]));
			if (pos[0] >= nr-1 && pos[1] >= ng-1 && pos[2] >= nb-1) {
				break;
			}
			pos[minrgb(pos[0], pos[1], pos[2])]++;
		}
		std::cout << ans << '\n';
	}
}