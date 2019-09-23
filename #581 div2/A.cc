#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int ans = (s.length()+1)/2;
	bool yes = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '1') {
			yes = 1;
		}
	}
	if (yes == 0 && s.length()%2==1) {
		ans --;
	}
	std::cout << ans;
}