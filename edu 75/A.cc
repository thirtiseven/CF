#include <iostream>
#include <string>
#include <set>

int n;
std::string s;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	while (n--) {
		std::set<char> ans;
		std::cin >> s;
		s = s + "*";
		int now = 1;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == s[i-1]) {
				now++;
			} else {
				if (now % 2 == 1) {
					ans.insert(s[i-1]);
				}
				now = 1;
			}
		}
		for (auto it: ans) {
			std::cout << it;
		}
		std::cout << '\n';
	}
}