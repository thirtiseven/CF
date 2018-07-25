#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	double n;
	std::cin >> n;
	std::cout << (floor((n+1)/2.0)*ceil((n+1)/2.0));
}