#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char *argv[]) {
	char s[100000];
	std::cin >> s;
	int pos1, pos2, pos3, b=0, len = strlen(s);
	for(int i = 0; i < len; i++) {
		if(s[i] == '.') {
			pos1 = i;
		} else if(s[i] == 'e') {
			pos2 = i;
			for(int j = i+1; j < len; j++) {
				b = 10 * b + s[j] - '0';
			}
		}
	}
	for(int i = pos1; i < std::min(pos1 + b, pos2); i++)
		s[i] = s[i+1];
	s[pos1 + b] = '.';
	while(s[pos2 - 1] == '0') {
		pos2--;
	}
	if(pos1 + b == pos2 - 1) {
		pos2--;
	} else if(pos1 + b >= pos2) {
		for(int i = 0; i < len; i++) {
			if(s[i] == 'e') {
				for(int j = i; j < pos1 + b; j++) {
					s[j] = '0';
				}
			}
		}
		pos2 = pos1 + b;
	}
	if(s[pos2-1] == '.') {
		pos2--;
	}
	pos3 = 0;
	while(pos3 < pos1 + b - 1 && s[pos3] == '0') {
		pos3++;
	}
	for(int i = pos3; i < pos2; i++) {
		std::cout << s[i];
	}
	return 0;
}