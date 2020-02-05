#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

const int maxn = 200000+7;

std::tuple<int, int, int> a[maxn], b[maxn];
int n, sa, ea, sb, eb;

bool cmp(std::tuple<int, int, int> a, std::tuple<int, int, int> b) {
	return std::get<2>(a) < std::get<2>(b);
}

int main(int argc, char *argv[]) {  
	std::cin >> n;
	int cnta = 0, cntb = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> sa >> ea >> sb >> eb;
		a[cnta] = std::make_tuple(sa, 1, i);
		cnta++;
		a[cnta] = std::make_tuple(ea, 2, i);
		cnta++;
		b[cntb] = std::make_tuple(sb, 1, i);
		cntb++;
		b[cntb] = std::make_tuple(eb, 2, i);
		cntb++;
	}
	std::sort(a, a+n*2);
	std::sort(b, b+n*2);
	int x = 0;
	bool yes = 1;
	for (int i = 0; i < 2*n; i++) {
		if (std::get<1>(a[i]) == 2) {
			x++;
		} else {
			if (x > 1) {
				std::sort(a+i-x, a+i, cmp);
			}
			x = 0;
		}
	}
	if (x > 1) {
		std::sort(a+n+n-x, a+n+n, cmp);
	}
	x = 0;
	for (int i = 0; i < 2*n; i++) {
		if (std::get<1>(b[i]) == 2) {
			x++;
		} else {
			if (x > 1) {
				std::sort(b+i-x, b+i, cmp);
			}
			x = 0;
		}
	}
	if (x > 1) {
		std::sort(b+n+n-x, b+n+n, cmp);
	}
	x = 0;
	for (int i = 0; i < 2*n; i++) {
		if (std::get<1>(a[i]) == 1) {
			x++;
		} else {
			if (x > 1) {
				std::sort(a+i-x, a+i, cmp);
			}
			x = 0;
		}
	}
	if (x > 1) {
		std::sort(a+n+n-x, a+n+n, cmp);
	}
	x = 0;
	for (int i = 0; i < 2*n; i++) {
		if (std::get<1>(b[i]) == 1) {
			x++;
		} else {
			if (x > 1) {
				std::sort(b+i-x, b+i, cmp);
			}
			x = 0;
		}
	}
	if (x > 1) {
		std::sort(b+n+n-x, b+n+n, cmp);
	}
	x = 0;
	for (int i = 0; i < 2*n; i++) {
		if (std::get<1>(a[i]) != std::get<1>(b[i]) && std::get<2>(a[i]) != std::get<2>(b[i])) {
			yes = 0;
		}
	}
	std::cout << (yes?"YES\n":"NO\n");
}