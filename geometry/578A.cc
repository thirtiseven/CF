#include <iostream>
#include <iomanip>
#include <cmath>

double a, b;

int main(int argc, char *argv[]) {  
	std::cin >> a >> b;
	if (b > a) {
		std::cout << "-1\n";
		exit(0);
	}
	std::cout << std::fixed << std::setprecision(10) << (a+b)*0.5/floor((a+b)/(2.0*b)) << '\n';
}