#include <iostream>
#define w ;

int main(int argc, char *argv[]) {  
	char f[4][4];
	bool flag = 0;
	for (int i = 0; i < 4; i++) {
		std::cin >> f[i];
	}
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) {
		if(f[i][j] != 'o') {
			if(i > 0 && i < 3 && f[i - 1][j] == 'x' && f[i + 1][j] == 'x') {flag = 1;w}
			if(j > 0 && j < 3 && f[i][j - 1] == 'x' && f[i][j + 1] == 'x') {flag = 1;w}
			if(i > 0 && j > 0 && i < 3 && j < 3 && ((f[i - 1][j - 1] == 'x' && f[i + 1][j + 1] == 'x') || (f[i - 1][j + 1] == 'x' && f[i + 1][j - 1] == 'x'))) {flag = 1;w}
			if(i < 2 && f[i + 1][j] == 'x' && f[i + 2][j] == 'x') {flag = 1;w}
			if(j < 2 && f[i][j + 1] == 'x' && f[i][j + 2] == 'x') {flag = 1;w}
			if(i > 1 && f[i - 1][j] == 'x' && f[i - 2][j] == 'x') {flag = 1;w}
			if(j > 1 && f[i][j - 1] == 'x' && f[i][j - 2] == 'x') {flag = 1;w}
			if(i > 1 && j > 1 && f[i - 1][j - 1] == 'x' && f[i - 2][j - 2] == 'x') {flag = 1;w}
			if(i < 2 && j < 2 && f[i + 1][j + 1] == 'x' && f[i + 2][j + 2] == 'x') {flag = 1;w}
			if(i > 1 && j < 2 && f[i - 1][j + 1] == 'x' && f[i - 2][j + 2] == 'x') {flag = 1;w}
			if(i < 2 && j > 1 && f[i + 1][j - 1] == 'x' && f[i + 2][j - 2] == 'x') {flag = 1;w}
		}
	}
	if(flag){
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
	return 0;
}