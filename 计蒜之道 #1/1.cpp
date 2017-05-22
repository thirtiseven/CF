#include <iostream>

struct chess{
	int x, y;
};
int m, n;
chess a[10], b[10];

int isin(int alice, int bob){
	for(int i = 0; i < n; i++) {
		if(a[i].x == alice && a[i].y == bob) {
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].x >> a[i].y;
	}
	for(int i = 0; i < m; i++) {
		std::cin >> b[i].x >> b[i].y;
	}
	int cnt = 0;
	if(isin(-3, 3) && isin(0, 3) && isin(3, 3)) {
		cnt++;
	}
	if(isin(-2, 2) && isin(0, 2) && isin(2, 2)) {
		cnt++;
	}
	if(isin(-1, 1) && isin(0, 1) && isin(1, 1)) {
		cnt++;
	}
	if(isin(-1, -1) && isin(0, -1) && isin(1, -1)) {
		cnt++;
	}
	if(isin(-2, -2) && isin(0, -2) && isin(2, -2)) {
		cnt++;
	}
	if(isin(-3, -3) && isin(0, -3) && isin(3, -3)) {
		cnt++;
	}
	if(isin(-3, 3) && isin(-3, 0) && isin(-3, -3)) {
		cnt++;
	}
	if(isin(-2, 2) && isin(-2, 0) && isin(-2, -2)) {
		cnt++;
	}
	if(isin(-1, 1) && isin(-1, 0) && isin(-1, -1)) {
		cnt++;
	}
	if(isin(1, 1) && isin(1, 0) && isin(1, -1)) {
		cnt++;
	}
	if(isin(2,2) && isin(2,0) && isin(2,-2)) {
		cnt++;
	}
	if(isin(3,3) && isin(3,0) && isin(3,-3)) {
		cnt++;
	}
	if(isin(0,1) && isin(0,2) && isin(0,3)) {
		cnt++;
	}
	if(isin(0,-1) && isin(0,-2) && isin(0,-3)) {
		cnt++;
	}
	if(isin(-3,0) && isin(-2,0) && isin(-1,0)) {
		cnt++;
	}
	if(isin(1,0) && isin(2,0) && isin(3,0)) {
		cnt++;
	}
	std::cout << cnt << std::endl;
	return 0;
}