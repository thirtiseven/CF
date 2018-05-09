#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string a, b;
	std::cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		std::cout << (a[i]==b[i]?0:1);
	}	
}