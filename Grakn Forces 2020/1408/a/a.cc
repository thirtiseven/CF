#include <iostream>
#include <algorithm>

const int maxn = 123;

int t, n, a[maxn], b[maxn], c[maxn], p[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			std::cin >> c[i];
		}
		p[0] = a[0];
		for (int i = 0; i < n; i++) {
			p[i] = a[i];
			if (p[i] == p[i-1]) {
				p[i] = b[i];
			}	
		}
		if (p[n-1] == p[0] || p[n-1] == p[n-2]) {
			p[n-1] = c[n-1];
			if (p[n-1] == p[0] || p[n-1] == p[n-2]) {
				p[n-1] = b[n-1];
				if (p[n-1] == p[0] || p[n-1] == p[n-2]) {
					p[n-1] = a[n-1];	
				}
			}
		}
		for (int i = 0; i < n; i++) {
			std::cout << p[i] << ' ';
		}
		std::cout << '\n';
	}
}