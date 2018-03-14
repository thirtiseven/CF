#include <iostream>
#include <utility>
#include <algorithm>
#include <iomanip>

int main(int argc, char *argv[]) {  
	int n;
	double f = 100000;
	double a, b, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> a >> b;
		f = std::min (f, a/b);
	}
	std::cout << std::fixed << std::setprecision(10) << f*m << std::endl;
}