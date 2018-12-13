#include <iostream>

int main(int argc, char *argv[]) {  
	int n, k;
	std::cin >> n >> k;
	std::cout << (2*n-1)/k+1+(5*n-1)/k+1+(8*n-1)/k+1 << '\n';
}