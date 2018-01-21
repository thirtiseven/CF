#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, k;
	std::cin >> n >> k;
	int ans = 0, tot;
	for (int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		if(k%t==0) {
			ans = std::max(ans, t);
		}
	}
	std::cout << k/ans;
	return 0;
}