#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 100000+7;

ll a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}
	std::sort(a+1, a+n+1);
	std::sort(b+1, b+n+1);
	ll nowa = n, nowb = n;
	ll as = 0, bs = 0;
	for (int i = 0; i < n; i++) {
		if (a[nowa] > b[nowb] && nowa > 0) {
			as += a[nowa];
			nowa--;
		} else {
			nowb--;
		}
		if (a[nowa] < b[nowb] && nowb > 0) {
			bs += b[nowb];
			nowb--;
		} else {
			nowa--;
		}
//		std::cout << as << " " << bs << '\n';
	}
	std::cout << as-bs;
}