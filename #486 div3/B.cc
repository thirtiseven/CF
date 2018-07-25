#include <iostream>
#include <string>
#include <algorithm>

bool cmp(std::string a, std::string b) {
	return a.length() < b.length();
}

int main(int argc, char *argv[]) {  
	int n;
	std::string s[102];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}
	std::sort(s, s+n, cmp);
	bool yes = 1;
	for (int i = 1; i < n; i++) {
		if (s[i].find(s[i-1]) == std::string::npos) {
			yes = 0;
			break;
		}
	}
	if (yes) {
		std::cout << "YES\n";
		for (int i = 0; i < n; i++) {
			std::cout << s[i] << '\n';
		}
	} else {
		std::cout << "NO\n";
	}
}