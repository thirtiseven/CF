#include <iostream>
#include <algorithm>

int T, n, m, k;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m >> k;
		int maxx = std::min(n/k, m);
		int minn = (m-maxx)/(k-1)+int((m-maxx)%(k-1)>0);
		std::cout << maxx - minn << '\n';
	}
}