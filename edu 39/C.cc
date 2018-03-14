#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int t = 0;
	for (int i = 0; i < s.length() && t < 26; i++) {
		if (s[i] <= 'a'+t) {
			s[i] = 'a'+t;
			t++;
		}
	}
	if (t == 26) {
		std::cout << s;
	} else {
		std::cout << "-1";
	}
}