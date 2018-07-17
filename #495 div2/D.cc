#include <iostream>
#include <cstring>
#include <algorithm>

const int maxn = 1e6+8;

int cor[maxn], now[maxn], tem[maxn];
int t, maxx = 0, x;
int minn = 0;

void check(int n, int m, int x, int y) {
	if (x>n || y>m) return;
	memset(tem, 0, sizeof(tem));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tem[std::abs(i-x)+std::abs(j-y)]++;
		}
	}
	for (int i = 0; i <= maxx; i++) {
		if (tem[i] != now[i]) return;
	}
	std::cout << n << " " << m << '\n' << x << " " << y;
	exit(0);
}

int main(int argc, char *argv[]) {  
	memset(now, 0, sizeof(now));
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> x;
		maxx = std::max(maxx, x);
		now[x]++;
	}
	if (t == 1 && x == 0) {
		std::cout << "1 1\n1 1";
		exit(0);
	}
	for (int i = 1; i <= maxx; i++) {
		if (i*4 > now[i]) {
			minn = i;
			break;
		}
	}
	for (int i = 1; i <= t; i++) {
		if (i*(t/i)==t) {
			check(i, t/i, minn, i+t/i-maxx-minn);
		}
	}
	std::cout << "-1\n";
}