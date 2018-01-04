#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' ||s[i] == '1' ||s[i] == '3' ||s[i] == '5' ||s[i] == '7' ||s[i] == '9') {
			cnt++;
		}
	}
	std::cout << cnt;
	return 0;
}