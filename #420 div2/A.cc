#include <iostream>
int n;
int ex[55][55];

int check(int opps, int i, int j) {
	for(int ii = 0; ii < n; ii++) {  
		if(ii == i) continue;  
		for(int jj = 0; jj < n; jj++) {  
			if(jj == j) continue;  
			if(ex[ii][j] + ex[i][jj] == opps) {
				return 0;
			}
		}  
	} 
	return 1;
}

int main(int argc, char *argv[]) {  
	std::cin >> n;
	bool flag = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> ex[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			  if(ex[i][j]==1) continue;
			if(check(ex[i][j], i, j)) {
				flag = 1;
				goto label;
			}
		}
	}
	label:
	if(flag) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
	}
	return 0;
}