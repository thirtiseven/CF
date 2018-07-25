#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::cin >> n >> s;
	bool yes = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '1' && s[i-1] == '1') {
			yes = 0;
		}
	}
	for (int i = 1; i < s.length()-1; i++) {
		if (s[i] == '0' && s[i-1] == '0' && s[i+1] == '0') {
			yes = 0;
		}
	}
	if (s[0] == '0' && s[1] == '0') yes = 0;
	if (s[s.length()-1] == '0' && s[s.length()-2] == '0') yes = 0;
	if (n == 1 && s[0] == '0') yes = 0;
	std::cout << (yes?"Yes":"No");
}