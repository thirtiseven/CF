#include <iostream>
#include <cmath>
#include <iomanip>

long double n, h;

long double f(long double x) {
	return sqrt(h*x);
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> h;
	long double pieces = h/n;
	for(int i = 1;i < n;i++) {
		std::cout << std::fixed << std::setprecision(12) << f(pieces*i) << " ";
	}
	return 0;
}

//70710.678118654752
//70710.678118654760 