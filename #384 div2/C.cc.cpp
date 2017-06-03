#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	if(n == 1) {
		std::cout << "-1" << std::endl;
	} else {
		std::cout << n << " " << (n+1) << " " << (n*(n+1)) << std::endl;
	}
	return 0;
}