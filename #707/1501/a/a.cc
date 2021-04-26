#include <iostream>
#include <algorithm>

const int maxn = 123;

int t, n;
int a[maxn], b[maxn], c[maxn], d[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		a[0] = b[0] = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i] >> b[i];
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> c[i];
			d[i] = a[i] - b[i-1];
		}
		int now = 0;
		for (int i = 1; i <= n; i++) {
			int diff = b[i] - a[i];
			a[i] = b[i-1] + c[i] + d[i];
			b[i] = std::max(b[i], a[i]+(diff+1)/2);
		}
		std::cout << a[n] << '\n';
	}
}