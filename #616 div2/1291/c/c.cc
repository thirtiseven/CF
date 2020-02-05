#include <iostream>

const int maxn = 3560;
int n, m, k, a[maxn], T;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		k = std::min(k, m-1);
		int ans = 0;
		for (int i = 0; i <= k; i++) {
			int minn = INT_MAX;
 			for (int j = 1; j <= m-k; j++) {
				minn = std::min(minn, std::max(a[i+j], a[i+j+n-m]));
			}	
			ans = std::max(minn, ans);
		}
		std::cout << ans << '\n';
	}
}