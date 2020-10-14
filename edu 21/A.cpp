#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

#define ll int

int main(int argc, char *argv[]) {  
	std::string str; 
	std::cin >> str; 
	ll i = std::stoi(str); 
	int len = str.length();
	int n = pow(10, len - 1);
	int first = i / n;
	std::cout << (first + 1) * n - i << std::endl;
	return 0;
}