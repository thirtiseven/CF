#include <iostream>

int main(int argc, char *argv[]) {  
	int t, s, x;
	std::cin >> t >> s >> x;
	x -= t;
	bool flag = 0;
	if(x%s == 0 || x%s == 1) flag = 1;
	if(x < 0) flag = 0;
	if(x == 0) flag = 1;
	if(x == 1) flag = 0;
	if(flag) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
	return 0;
}