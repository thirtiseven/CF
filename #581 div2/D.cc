#include <iostream>
#include <string>

std::string s;

int main(int argc, char *argv[]) {  
	std::cin >> s;
	int ans = 0;
	for (int i = s.length()-1; i >= 0; i--) {
		if (s[i] == '0') {
			ans++;
		} else {
			if (ans <= 0) {
				s[i] = '0';
			} else {
				ans--;
			}
		}
	}
	std::cout << s;
}