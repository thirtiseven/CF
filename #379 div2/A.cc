#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::cin >> n >> s;
	int Anton = 0, Danik = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'A') {
			Anton++;
		} else {
			Danik++;
		}
	}
	if(Anton > Danik) {
		std::cout << "Anton";
	} else if(Danik > Anton) {
		std::cout << "Danik";
	} else {
		std::cout << "Friendship";
	}
	return 0;
}