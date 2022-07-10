#include <iostream>
#include <algorithm>

int T;
int n, k;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> k;
		if (k <= (n+1)/2) {
			std::string line = "";
			for (int i = 0; i < n; i++) {
				line += ".";
			}
			std::string ans[n];
			for (int i = 0; i < n; i++) {
				ans[i] = line;
			}
			for (int i = 0; i < k; i++) {
				ans[2*i][2*i] = 'R';
			}
			for (int i = 0; i < n; i++) {
				std::cout << ans[i] << '\n';
			}
		} else {
			std::cout << "-1\n";
		}
	}
	
}