#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int yes = 0;
	int len = s.length();
	if (len < 3) {
		std::cout << "No";
		return 0;
	}
	for (int i = 0; i < len-2; i++) {
		std::string ss = s.substr(i, 3);
//		std::cout << ss << '\n';
		if (ss == "ABC" || ss == "ACB" || ss == "BAC" || ss == "BCA" || ss == "CAB" || ss == "CBA") {
			yes = 1;
			break;
		}
	}
	if (yes) {
		std::cout << "Yes";
	} else {
		std::cout << "No";
	}
}