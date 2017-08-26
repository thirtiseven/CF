#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	std::string s[1010];
	bool flag = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> s[i];
		if(s[i][0] == 'O' && s[i][1] == 'O' && !flag) {
			flag = 1;
			s[i][0] = '+', s[i][1] = '+';
		} else if(s[i][3] == 'O' && s[i][4] == 'O' && !flag) {
			flag = 1;
			s[i][3] = '+', s[i][4] = '+';
		}
	}
	if(flag) {
		std::cout << "YES\n";
		for(int i = 0; i < n; i++) {
			std::cout << s[i] << '\n';
		}
	} else {
		std::cout << "NO\n";
	}
	return 0;
}