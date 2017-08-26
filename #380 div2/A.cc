#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::cin >> n >> s;
	bool invert = 1;
	while(1) {
		if(invert == 1 && s[i] == 'o') {
			i++;
			invert = !invert;
		} else if(invert == 0 && s[i] == 'g') {
			i++;
			invert = !invert;
		} else {
			std::cout << "***";
			invert = 1;
		}
	}
	return 0;
}