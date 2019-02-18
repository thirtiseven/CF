#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int y, b, r;
	std::cin >> y >> b >> r;
	int ans = 0;
	b--;
	r-=2;
	std::cout << std::min(y, std::min(b, r))*3+3;
}