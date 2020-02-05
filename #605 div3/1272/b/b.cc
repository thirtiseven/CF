#include <iostream>
#include <string>

int q;
std::string s;

int main(int argc, char *argv[]) {  
	std::cin >> q;
	while (q--) {
		int L = 0, R = 0, U = 0, D = 0;
		std::cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'L') {
				L++;
			} else if (s[i] == 'R') {
				R++;
			} else if (s[i] == 'U') {
				U++;
			} else if (s[i] == 'D') {
				D++;
			}
		}
		int ans1 = std::min(L, R);
		int ans2 = std::min(U, D);
		int ans;
		if (ans1 == 0 && ans2 != 0) {
			ans2 = 1;
		}
		if (ans2 == 0 && ans1 != 0) {
			ans1 = 1;
		}
		std::cout << ans1*2+ans2*2 << '\n';
		for (int i = 0; i < ans1; i++) {
			std::cout << "L";
		}
		for (int i = 0; i < ans2; i++) {
			std::cout << "U";
		}
		for (int i = 0; i < ans1; i++) {
			std::cout << "R";
		}
		for (int i = 0; i < ans2; i++) {
			std::cout << "D";
		}
		std::cout << '\n';
	}
}