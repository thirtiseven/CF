#include <iostream>

int main(int argc, char *argv[]) {  
	long long l, r;
	std::cin >> l >> r;
	if(r == l || r - l == 1) {
		std::cout << l << "\n";
	}else {
		std::cout << "2\n";
	}
	return 0;
}