#include <iostream>
#include <algorithm>
#define maxn 100009

int main(int argc, char *argv[]) {  
	int n, a, x[maxn];
	std::cin >> n >> a;
	for(int i = 0; i < n; i++) {
		std::cin >> x[i];
	}
	if (n==1) {
		std::cout << 0 << std::endl;
		return 0;
	}
	std::sort(x, x+n);
	std::cout << std::min(x[n-1] - x[1] + std::min(std::abs(x[n-1]-a), std::abs(x[1]-a)), x[n-2] - x[0] + std::min(std::abs(x[0]-a), std::abs(x[n-2]-a))) << std::endl;
	return 0;
}