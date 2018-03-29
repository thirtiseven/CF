#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::cin >> n >> s;
	for (int i = 0; i < s.length();) {
		if (s[i] == 'R' && i != s.length()-1 && s[i+1] == 'U') {
			n--;
			i+=2;
		} else if (s[i] == 'U' && i != s.length()-1 && s[i+1] == 'R') {
			n--;
			i+=2;
		} else {
			i++;
		}
	}
	std::cout << n;
}