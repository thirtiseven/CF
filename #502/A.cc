#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, sum[1234], a, b, c, d, x;
	std::cin >> n;
	std::cin >> a >> b >> c >> d;
	x = a+b+c+d;
	sum[0] = -x;
	for (int i = 1; i < n; i++) {
		std::cin >> a >> b >> c >> d;
		sum[i] = -(a+b+c+d);
	}
	std::sort(sum, sum+n);
	std::cout << std::lower_bound(sum, sum+n, -x)-sum+1<< '\n';
}