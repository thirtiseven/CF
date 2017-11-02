#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {
	int n, x; 
	int i;
	char c = 'a';
	std::cin >> n;
	do{
		x=(1 + sqrt(1 + 8 * n)) / 2 + 1e-6;
		for(i=0;i<x;++i)
			std::cout<<c;
		++c;
		n-=(x-1)*x/2;
	} while(n);
	return 0;
}