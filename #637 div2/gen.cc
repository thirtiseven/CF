#include <iostream>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cout << "1000 2000\n";
	for (int i = 0; i < 1000; i++) {
		std::cout << "0000000\n";
	}
}