#include <iostream>
#include <cstring>

int yes[300];

int main(int argc, char *argv[]) {  
	int n, t;
	std::cin >> n;
	memset(yes, 0, sizeof(yes));
	for(int i = 0; i <= 33; i++) {
		for(int j = 0; j <= 14; j++) {
			yes[3*i+7*j] = 1;
		}
	}
	for(int i = 0; i < n; i++) {
		std::cin >> t;
		if(yes[t]) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
	return 0;
}