#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	int n;
	std::cin >> n >> s;
	int con = 0;
	int ans = 0;
	for (int i = 0; i < s.length();) {
		while (s[i] == 'x') {
			con++;
			i++;
		}
		if (s[i] != 'x') {
			if (con >= 3) {
				ans += con-2;
//				std::cout << con << " " << ans << '\n';
			}
			con = 0;
			i++;
		}
	}
	if (con >= 3) {
		ans += con-2;
//		std::cout << con << " " << ans << '\n';
	}
	std::cout << ans;
}