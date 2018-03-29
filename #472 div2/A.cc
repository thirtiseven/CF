#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	bool yes = 0;
	std::cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			if (i == 0 || i == n-1 || s[i-1] == s[i+1] || s[i+1] == '?') {
				yes = 1;
			}
		}
		if (i < n-1 && s[i] == s[i+1] && s[i] != '?') {
			yes = 0;
			break;
		}
	}
	std::cout << (yes?"YES\n":"NO\n");
}