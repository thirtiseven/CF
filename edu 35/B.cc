#include <iostream>
#include <algorithm>
#include <cmath>

int main(int argc, char *argv[]) {  
	int n, a, b;
	std::cin >> n >> a >> b;
	int ans;
	int num0 = floor(n*a/(a+b));
	int num1 = ceil(n*a/(a+b));
	if(num1 == 0) {
		num1++;
	}
	if(num0 == 0) {
		num0++;
	}
	ans = std::max(std::min(a/num0, b/(n-num0)), std::min(a/num1, b/(n-num1)));
	std::cout << ans;
	return 0;
}