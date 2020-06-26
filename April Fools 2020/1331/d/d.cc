#include <iostream>
#include <string>

std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> s;
	s = s.substr(1);
	int x = std::stoi(s);
	std::cout << (x%2);
}