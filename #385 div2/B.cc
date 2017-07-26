#include <iostream>
#include <cmath>

#define inf 1010

int main(int argc, char *argv[]) {  
	int n, m;
	bool table[510][510];
	std::cin >> n >> m;
	bool change = 0;
	int mi = inf, mj = inf, xi = -1, xj = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char tempc;
			std::cin >> tempc;
			if(tempc == 'X') {
				table[i][j] = 1;
				change = 1;
				mi = std::min(mi, i);
				mj = std::min(mj, j);
				xi = std::max(xi, i);
				xj = std::max(xj, j);
			} else {
				table[i][j] = 0;
			}
		}
	}
	//std::cout << mi << mj << xi << xj << std::endl;
	bool flag = 1;
	for(int i = mi; i <= xi; i++) {
		for(int j = mj; j <= xj; j++) {
			//std::cout << table[i][j] << " ";
			if(!table[i][j]) {
				flag = 0;
			}
		}
	}
	if(flag) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
	return 0;
}