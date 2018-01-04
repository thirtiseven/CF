#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, num[3], t;
	memset(num, 0, sizeof(num));
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> t;
		num[t]++;
	}
	int ans = std::min(num[1], num[2]) + std::max(0, num[1] - num[2])/3;
	std::cout << ans << '\n';
	return 0;
}