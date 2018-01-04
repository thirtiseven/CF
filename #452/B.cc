#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int a[30];
	int b[30] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int c[30] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool yes = 1;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < 24; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[j] != b[(j+i)%24]) {
				break;
			}
			if(j == n) {
				yes = 1;
				std::cout << "YES\n";
				return 0;
			}
		}
	}
	for(int i = 0; i < 24; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[j] != c[(j+i)%24]) {
				break;
			}
			if(j == n) {
				yes = 1;
				std::cout << "YES\n";
				return 0;
			}
		}
	}
	std::cout << "NO\n";
	return 0;
	return 0;
}