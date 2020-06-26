#include <iostream>
#include <vector>
#include <string>

const int maxn = 1004;

int n, m;
std::string s[maxn];

int check(int x, int y) {
	if (x == -1 || x == n) {
		return 1;
	}
	if (y == -1 || y == m) {
		return 1;
	}
	if (s[i][j] == '.') {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') {
				int cnt = 0;
				cnt += check(i-1, j);
				cnt += check(i+1, j);
				cnt += check(i, j-1);
				cnt += check(i, j+1);
				if (cnt >= 2) {
					s[i][j] = 'S';
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
		}
	}
}