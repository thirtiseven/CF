#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

const int maxn = 1e5+7;

int t, n;
int u, v;
int x[maxn], y[maxn];

int myabs(int xx) {
	if (xx < 0) {
		return -xx;
	}
	return xx;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		int cntx = 0, cnty = 0;
		std::cin >> n;
		for (int i = 0; i < 2 * n; i++) {
			std::cin >> u >> v;
			if (u == 0) {
				y[cnty] = myabs(v);
				cnty++;
			} else {
				x[cntx] = myabs(u);
				cntx++;
			}
		}
		std::sort(x, x+n);
		std::sort(y, y+n);
		double ans = 0;
		for (int i = 0; i < n; i++) {
			ans += sqrt(double(x[i])*double(x[i])+double(y[i])*double(y[i]));
		}
		std::cout << std::fixed << std::setprecision(15) << ans << '\n';
	}
}