#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
 
int main(int argc, char *argv[]) {  
	std::string a, b;
	std::cin >> a >> b;
	std::transform(a.begin(), a.end(), a.begin(), ::tolower);
	std::transform(b.begin(), b.end(), b.begin(), ::tolower);
	if (a==b) {
		std::cout << 0;
	} else {
		std::cout << (a>b?"1":"-1");
	}
}