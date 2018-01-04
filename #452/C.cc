#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	if(n%4==0) {
		std::cout << "0\n" << n/2;
		for(int i = 1; i < n/2; i+=2) {
			std::cout << " " << i << " " << n+1-i;
		}
	} else if(n%4==1) {
		std::cout << "1\n" << n/2;
		for(int i = 1; i < (n-1)/2; i+=2) {
			std::cout << " " << i+1 << " " << n+1-i;
		}
	} else if(n%4==2) {
		std::cout << "1\n" << n/2;
		for(int i = 1; i < n/2-1; i+=2) {
			std::cout << " " << i << " " << n+1-i;
		}
		std::cout << " " << n/2 << '\n';
	} else {
		std::cout << "0\n" << n/2+1 << " 1";
		for(int i = 1; i < n/2-1; i+=2) {
			std::cout << " " << i+1 << " " << n+1-i;
		}
		std::cout << " " << n/2+1 << '\n';
	}
	return 0;
}