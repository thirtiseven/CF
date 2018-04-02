#include <iostream>
#include <algorithm>


int main(int argc, char *argv[]) {  
	long long a, b, x, y, z, aa, bb;
	std::cin >> a >> b >> x >> y >> z;
	aa = 2*x + y;
	bb = 3*z + y;
	
	std::cout << std::max(aa-a, (long long)0)+std::max(bb-b,(long long)0);
}