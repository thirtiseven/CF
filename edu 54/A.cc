#include <iostream>
#include <string>

std::string s;
int n;
int flag;

int main(int argc, char *argv[]) {  
	std::cin>> n >> s;
	for (int i = 1; i < n; i++) {
		if (flag) { printf("%c", s[i]); continue; }
		if (s[i] < s[i - 1]) {
			flag = 1;
			printf("%c", s[i]);
		}
		else printf("%c", s[i - 1]);
	}
	return 0;
}