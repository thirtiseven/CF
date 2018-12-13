#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::sort(s.begin(), s.end());
	std::cout << s;
}