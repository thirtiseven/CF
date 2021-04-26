#include <iostream>
#include <algorithm>
#include <string>

int h, w;
std::string s[5];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> h >> w;
	for (int i = 0; i < h; i++) {
		std::cin >> s[i];
	}
	int x = 0, y = 0, ans = 0;
	while (1) {
//		std::cerr << x << ' ' << y << '\n';
		if (s[y][x] == '*') {
			ans++;
		}
		if (x == w-1 && y == h-1) {
			break;
		} else if (x == w-1) {
			y++;
		} else if (y == h-1) {
			x++;
		} else if (s[y+1][x] == '*') {
			y++;
		} else {
			x++;
		}
	}
	std::cout << ans << '\n';
}