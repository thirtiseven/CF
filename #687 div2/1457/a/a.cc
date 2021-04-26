#include <iostream>
#include <algorithm>

int T, n, m, r, c;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m >> r >> c;
		std::cout << std::max(std::max(r-1+c-1, n-r+c-1), std::max(n-r+m-c, r-1+m-c)) << '\n';
	}
}