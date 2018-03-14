#include <iostream>

const int maxn = 1e5+9;
using ll = long long;

int main(int argc, char *argv[]) {  
	ll m, n, x[maxn], y[maxn];
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> x[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> y[i];
	}
	ll ans = 0;
	ll cx = 0, cy = 0;
	ll totx = 0, toty = 0;
	while (cx < n) {
		totx += x[cx];
		cx++;
		while (toty < totx) {
			toty += y[cy];
			cy++;
		}
		if (totx == toty) {
			ans++;
//			std::cout << totx << " " << cx << " " << cy << '\n';
			toty = 0;
			totx = 0;
		}
	}
	std::cout << ans;
}