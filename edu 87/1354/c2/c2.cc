#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

#define PI 3.14159265

int T;

double n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		n *= 2.0;
		std::cout << std::fixed << std::setprecision(10) << 1/(-2*std::cos((n+1.0)/(2.0*n)*PI)) << '\n';
	}
}