#include <iostream>

const int maxn = 1e5+7;

int n, q, r, c;
int maze[4][maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int cnt = 0;
	std::cin >> n >> q;
	while (q--) {
		std::cin >> r >> c;
		int x = maze[r-1][c-1] + maze[r-1][c] + maze[r-1][c+1] + maze[r+1][c-1] + maze[r+1][c] + maze[r+1][c+1];
		maze[r][c] ^= 1;
		if (maze[r][c]) {
			cnt += x;
		} else {
			cnt -= x;
		}
		if (cnt > 0) {
			std::cout << "No\n";
		} else {
			std::cout << "Yes\n";
		}
	}
}