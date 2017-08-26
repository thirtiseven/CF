#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s1, s2;
	std::cin >> s1;
	s2 = s1;
	std::reverse(s1.begin(), s1.end());
	std::cout << s2 << s1;
	return 0;
}