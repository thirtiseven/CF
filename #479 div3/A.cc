#include <iostream>

int main(int argc, char *argv[]) {  
	int n, k;
	std::cin >> n >> k;
	while (k--) {
		if (n%10!=0) {
			n--;
		} else {
			n/=10;
		}
	}	
	std::cout << n;
}