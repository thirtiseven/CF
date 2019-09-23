#include <iostream>

int main(int argc, char *argv[]) {  
	int w1, h1, w2, h2;
	std::cin >> w1 >> h1 >> w2 >> h2;
	std::cout<< (h1+h2+w1) * 2 + 4;
}