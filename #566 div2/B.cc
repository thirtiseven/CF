#include <iostream>
#include <string>
#include <algorithm>

int w, h;
const int maxn = 502;
std::string s[maxn];
int x[maxn], y[maxn];


int main(int argc, char *argv[]) {  
	std::fill(x, x+maxn, 0);
	std::fill(y, y+maxn, 0);
	std::cin >> h >> w;
	for (int i = 0; i < h; i++) {
		std::cin >> s[i];
	}
	bool isempty = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '*') {
				isempty = 0;
				x[j]++;
				y[i]++;
			}
		}
	}
	if (isempty) {
		std::cout << "NO\n";
		exit(0);
	}
	int up = 0, down = h-1, left = 0, right = w-1, xx = -1, yy = -1;
	while (y[up] == 0) {
		up++;
	}
	while (y[down] == 0) {
		down--;
	}
	while (x[left] == 0) {
		left++;
	}
	while (x[right] == 0) {
		right--;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (y[i] > 1 && x[j] > 1) {
				if (xx == -1 && yy == -1) {
					yy = i, xx = j;
				} else {
					std::cout << "NO\n";
					exit(0);
				}
			}
		}
	}
	if (xx == -1 || yy == -1) {
		std::cout << "NO\n";
		exit(0);
	}
	if (!(xx > 0 && xx < w && yy > 0 && yy < h)) {
		std::cout << "NO\n";
		exit(0);
	}
	if (!(s[xx][yy]=='*' && s[xx-1][yy]=='*' && s[xx+1][yy]=='*' && s[xx][yy-1]=='*' && s[xx][yy+1]=='*')) {
		std::cout << "NO\n";
		exit(0);
	}
	bool yes = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if ((s[i][j] == '*') != (j >= left && j <= right && i >= up && i <= down && (j==xx||i==yy))) {
				yes = 0;
			}		
		}
	}
	if (yes == 1) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}