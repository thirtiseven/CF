#include <iostream>
#include <algorithm>

const int maxn = 123;
int n, x, t, a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while(t--) {
		std::cin >> n >> x;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		std::sort(a, a+n);
		std::sort(b, b+n);
		std::reverse(b, b+n);
		bool yes = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] + b[i] > x) {
				yes = 0;
				break;
			}
		}
		std::cout << (yes?"Yes\n":"No\n");
	}
}