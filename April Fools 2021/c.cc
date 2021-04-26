#include <iostream>
#include <algorithm>
#include <string>

int toint(char c) {
	return int(c-'A');
}

char tochar(int x) {
	return 'A'+(x%26);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::string s;
	std::cin >> s;
	bool yes = 1;
	for (int i = 2; i < s.length(); i++) {
		if (tochar(toint(s[i-1])+toint(s[i-2])) != s[i]) {
			yes = 0;
			break;
		}
	}
	if (yes) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}