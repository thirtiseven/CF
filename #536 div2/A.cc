#include <iostream>
#include <string>

const int maxn = 501;

std::string m[maxn];

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> m[i];
	}
	int ans = 0;
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < n-1; j++) {
			if (m[i][j] == 'X' && m[i-1][j-1] == 'X' && m[i-1][j+1] == 'X' && m[i+1][j-1] == 'X' && m[i+1][j+1] == 'X') {
				ans++;
			}
		}
	}
	std::cout << ans;
}