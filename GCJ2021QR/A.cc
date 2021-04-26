#include <iostream>
#include <algorithm>

const int maxn = 123;

int T, n, L[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int C = 1; C <= T; C++) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> L[i];
		}
		int ans = 0;
		for (int i = 0; i < n-1; i++) {
			int j = i;
			for (int k = i; k <= n-1; k++) {
				if (L[k] < L[j]) {
					j = k;
				}
			}
			std::reverse(L+i, L+j+1);
//			std::cout << (j-i+1) << '\n';
			ans += (j-i+1);
		}
		std::cout << "Case #" << C << ": " << ans << '\n';
	}
}