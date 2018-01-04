#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int ans = 0;
	int len = s.length();
	for(int i = 0; i < len-2; i++) {
		if(s[i] == 'Q') {
			for(int j = i+2; j < len; j++) {
				if(s[j] == 'Q') {
					for(int h = i+1; h < j; h++) {
						if(s[h] == 'A') {
							ans++;
						}
					}
				}
			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}