#include <iostream>
#include <string>

std::string s;

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		std::string even = "", odd = "";
		std::cin >> s;
		for (auto it: s) {
			if (int(it-'0') % 2 == 0) {
				even += it;
			} else {
				odd += it;
			}
		}
		even += "?";
		odd += "?";
		int now1 = 0, now2 = 0;
		for (int i = 0; i < s.length(); i++) {
			if (even[now1] < odd[now2]) {
				std::cout << even[now1];
				now1++;
			} else {
				std::cout << odd[now2];
				now2++;
			}
		}
		std::cout << '\n';
	}
}