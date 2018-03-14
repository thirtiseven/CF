#include <iostream>

int main(int argc, char *argv[]) {  
	long long k;
	std::cin >> k;
	if (k > 18*2) {
		std::cout << "-1";
	} else {
		if(k%2==1) {
			std::cout << "4";
		}
		for (int i = 0; i < k/2; i++) {
			std::cout << "8";
		}
	}
}