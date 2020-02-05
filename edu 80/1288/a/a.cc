#include <iostream>
#include <climits>
#include <cmath>

int T, n, d, x;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> d;
		int minn = INT_MAX;
		for (int i = 0; i*i <= d; i++) {
			minn = std::min(minn, int(std::ceil(double(d)/double(i+1)))+i);
		}
		std::cout << (minn <= n? "YES\n":"NO\n");
	}
}