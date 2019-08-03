#include <iostream>
#include <algorithm>

const int maxn = 102;
int n;
std::string s[maxn];
const std::string ss = "..................................................";
const std::string sss = "....................................................................................................";

bool yes(int a, int b, int c) {
	bool left = 0, right = 0, up = 0, down = 0;
	for (int i = 0; i < c; i++) {
		if (s[a+i][b] == '#') {
			left = 1;
			break;
		}
	}
	for (int i = 0; i < c; i++) {
		if (s[a+i][b+c-1] == '#') {
			right = 1;
			break;
		}
	}
	for (int i = 0; i < c; i++) {
		if (s[a+c-1][b+i] == '#') {
			down = 1;
			break;
		}
	}
	for (int i = 0; i < c; i++) {
		if (s[a][b+i] == '#') {
			up = 1;
			break;
		}
	}
	if ((up||left)&&(up||right)&&(down||left)&&(down||right)) {
		return 1;
	}
	return 0;
}

bool out(int a, int b, int c) {
	for (int i = 0; i <= c; i++) {
		if (s[a+i][b+c] == '#') {
			return 0;
		}
		if (s[a+c][b+i] == '#') {
			return 0;
		}
	}
	if (a != 0) {
		for (int i = 0; i <= c; i++) {
			if (s[a-1][b+i] == '#') {
				return 0;
			}
		}
	}
	if (b != 0) {
		for (int i = 0; i <= c; i++) {
			if (s[a+i][b-1] == '#') {
				return 0;
			}
		}
	}
	if (a != 0 && b != 0) {
		if (s[a-1][b-1] == '#') {
			return 0;
		}
	}
	return 1;
}

void paint(int a, int b, int c) {
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			s[a+i][b+j] = '.';
		}
	}
}

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
		s[i] += ss;
	}
	for (int i = n; i < n+50; i++) {
		s[i] = sss;
	}
	int ans = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
//				std::cout << i << ' ' << j << ' ' << k << ' ' << yes(i, j, k) << ' ' << out(i, j, k) << '\n';
				if (yes(i, j, k) && out(i, j, k)) {
					ans += k;
					paint(i, j, k);
				}
			}
		}
	}
	std::cout << std::min(ans, n) << '\n';
}