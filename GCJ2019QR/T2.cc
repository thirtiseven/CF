#include <iostream>
#include <string>

int main(int argc, char *argv[]) { 
	std::string s, ans;
	int n, T; 
	std::cin >> T; 
	for (int i = 1; i <= T; i++) {
		std::cin >> n >> s;
		std::cout << "Case #" << i << ": ";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'E') std::cout << 'S';
			else std::cout << 'E';
		}
		std::cout << '\n';
	}
}