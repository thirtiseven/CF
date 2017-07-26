#include <iostream>

int main(int argc, char *argv[]) {  
	int n, m, l, r;
	std::cin >> n >> m;
	int min_mex = 10000000;
	for(int i = 0; i < m; i++) {
		std::cin >> l >> r;
		min_mex = std::min(min_mex, r - l + 1);
	}
	std::cout << min_mex << std::endl;
	for(int i = 0; i < n; i++) {
		std::cout << (n-i) % min_mex << " ";
	}	
	std::cout << "\n";
	return 0;
}