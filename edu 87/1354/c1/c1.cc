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
		std::cout << std::fixed << std::setprecision(7) << 1.0/std::tan(PI/(2*n)) << '\n';
	}
}