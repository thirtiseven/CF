#include <iostream>
#include <algorithm>

int T, n, ans1, ans2, ans3;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		bool find = 0;		
		for (int i = 0; i <= n/7; i++) {
			for (int j = 0; i * 7 + j * 5 <= n; j++) {
				if ((n - (i * 7 + j * 5))% 3 == 0) {
					find = 1;
					std::cout << (n - (i * 7 + j * 5))/3 << ' ' << j << ' ' << i << '\n';
					goto out;
				}
			}
		}
		std::cout << "-1\n";
		out:;
	}
}