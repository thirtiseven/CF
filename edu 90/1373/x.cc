#include <iostream>
#include <algorithm>
#include <string>

int digsum(int x) {
	int res = 0;
	while (x) {
		res += x%10;
		x /= 10;
	}
	return res;
}

int x[3000];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::fill(x, x+3000, -1);
	for (int i = 0; i < 1000000; i++) {
		int temp = digsum(i) + digsum(i+1) + digsum(i+2);
		if (x[temp] == -1) {
			x[temp] = i;
		}
	}
	for (int i = 1; i <= 150; i++) {
		std::cout << x[i] << ", ";
	}
}