#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	std::cout << (n%4==3||n%4==0?"0\n":"1\n");
}