#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s, d;
	bool yes = 0;
	std::cin >> s;
	for (int i = 0; i < 5; i++) {
		std::cin >> d;
		if (s[0] == d[0] || s[1] == d[1]) {
			yes = 1;
		}
	}
	std::cout << (yes?"YES\n":"NO\n");
}