#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int num = 0;
	for (char i: s) {
		if (i=='4'||i=='7') {
			num++;
		}
	}
	std::string luck = std::to_string(num);
	num = 0;
	for (char i: luck) {
		if (i=='4'||i=='7') {
			num++;
		}
	}
	if (num == luck.length()) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}