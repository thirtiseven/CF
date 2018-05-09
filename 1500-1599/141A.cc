#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char *argv[]) {  
	std::string a, b, c;
	std::cin >> a >> b >> c;
	a = a+b;
	std::sort(a.begin(), a.end());
	std::sort(c.begin(), c.end());
	if (a == c) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}