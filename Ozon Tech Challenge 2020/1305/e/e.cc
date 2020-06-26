#include <iostream>

using ll = long long;
const int maxn = 5012;
const int inf = 1e9;

ll ans[maxn], n, m;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	ans[1] = 1;
	ans[2] = 2;
	for (int i = 3; i <= n; i++) {
		if (m == 0) {
			ans[i] = inf-n+i;
		} else {
			ans[i] = ans[i-1] + ans[i-2];
			m--;
		}
		if (ans[i] > inf-n+i) {
			std::cout << "-1\n";
			exit(0);
		}
	}
	if (m > 0) {
		std::cout << "-1\n";
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << ' '; 
	}
}