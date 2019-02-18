#include <iostream>
#include <string>

std::string s;
int n;
std::string t;
int r = 0;

char other(char a, char b) {
	if (a == 'R') {
		if (b == 'R' || b == 'G') {
			return 'B';
		}
		return 'G';
	} else if (a == 'B') {
		if (b == 'B' || b == 'G') {
			return 'R';
		}
		return 'G';
	}
	if (b == 'G' || b == 'B') {
		return 'R';
	} else {
		return 'B';
	}
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> s;
	s += "B";
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i-1]) {
			s[i] = other(s[i-1], s[i+1]);
			r++;
		}
	}
	std::cout << r << '\n';
	for (int i = 0; i < n; i++) {
		std::cout << s[i];
	}
}