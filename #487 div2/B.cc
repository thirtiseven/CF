#include <iostream>
#include <string>

std::string s;
int n, p;

int main(int argc, char *argv[]) {  
	std::cin >> n >> p >> s;
	int yes = 1;
	for (int i = 0; i < n-p; i++) {
		if (s[i] != s[i+p]) {
			switch (s[i]) {
				case '1':
					s[i+p] = '0';
					break;
				case '0':
					s[i+p] = '1';
					break;
				case '.':
					{
						if (s[i+p] == '0') {
							s[i] = '1';
						} else {
							s[i] = '0';
						}
						break;
					}
				default:break;
			}
			yes = 0;
			break;
		} else if (s[i] == s[i+p] && s[i] == '.') {
			s[i] = '0';
			s[i+p] = '1';
			yes = 0;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '.') {
			s[i] = '0';
		}
	}
	if (yes) {
		std::cout << "NO\n";
	} else {
		std::cout << s;
	}
}