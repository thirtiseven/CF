#include <iostream>
#define maxn 110

int main(int argc, char *argv[]) {  
	int m, n;
	bool flag = 0;
	std::cin >> n >> m;
	char im[maxn][maxn];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j	++) {
		    std::cin >> im[i][j];
			if(im[i][j] == 'C' || im[i][j] == 'M' || im[i][j] == 'Y') {
				flag = 1;
			}
		}
	}
	if(flag) {
		std::cout << "#Color\n";
	} else {
		std::cout << "#Black&White\n";		
	}
	return 0;
}