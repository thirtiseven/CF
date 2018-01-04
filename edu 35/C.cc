#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int k[5];
	std::cin >> k[0] >> k[1] >> k[2];
	bool yes = 0;
	std::sort(k, k+3);
	if(k[0] == 1) {
		yes = 1;
	} else if(k[0] == 2 && k[1] == 2){
		yes = 1;
	} else if(k[0] == 2 && k[1] == 4 && k[2] == 4) {
		yes = 1;
	} else if(k[0] == 3 && k[1] == 3 && k[2] == 3) {
		yes = 1;
	}
	if(yes) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
	return 0;
}