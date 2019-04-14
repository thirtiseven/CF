#include <iostream>
#include <algorithm>

const int maxn = 1e3+7;

int n, h, a[maxn], b[maxn];

void copy(int nn) {
	for (int i = 1; i <= nn; i++) {
		b[i] = a[i];
	}
	b[0] = 0;
}

bool check(int k) {
	copy(k);
	std::sort(b+1, b+k+1);
	int now = 0;
	for (int i = k; i >= 1; i -= 2) {
		now += std::max(b[i], b[i-1]);
	}
	if (now > h) {
		return false;
	}
	return true;
}

int main(int argc, char *argv[]) {  
	int ans = 0;
	std::cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (!check(i)) {
			std::cout << i-1;
			exit(0);
		}
	}
	std::cout << n;
}