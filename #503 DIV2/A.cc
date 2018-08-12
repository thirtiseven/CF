#include <iostream>

int main(int argc, char *argv[]) {  
	int n, h, a, b, k, ta, fa, tb, fb;
	std::cin >> n >> h >> a >> b >> k;
	for (int i = 0; i < k; i++) {
		std::cin >> ta >> fa >> tb >> fb;
		int ans;
		if (fa > b && fb > b && ta != tb) {
			ans = fa-b+fb-b+std::abs(tb-ta);
		} else if (fa < a && fb < a && ta != tb) {
			ans = 2*a-fa-fb+std::abs(tb-ta);
		} else {
			ans = std::abs(fa-fb)+std::abs(tb-ta);
		}		
		std::cout << ans << '\n';
	}
}