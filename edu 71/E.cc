#include <iostream>

int main(int argc, char *argv[]) {  
	std::cout << "?";
	for (int i = 0; i < 100; i++) {
		std::cout << " " << i;
	}
	std::cout << std::endl;
	long long pre = 16256, shu = 127, x;
	std::cin >> x;
	pre = x&pre;
	std::cout << "?";
	for (int i = 0; i < 100; i++) {
		std::cout << " " << 128+i*128;
	}
	std::cout << std::endl;
	std::cin >> x;
	shu = x&shu;
	std::cout << "! " << pre+shu << std::endl;
}