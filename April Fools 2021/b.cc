#include <iostream>
#include <algorithm>
#include <cmath>

int gao(int x) {
	int ans = 0;
	while (x) {
		ans += x%10;
		x /= 10;
	}
	return ans;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int x;
	std::cin >> x;
	while (x >= 10) {
		x = gao(x);
	}
	std::cout << x << '\n';
}