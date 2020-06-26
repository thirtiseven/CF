#include <iostream>
#include <algorithm>

const int maxn = 123;

int t, n, a[maxn], b[maxn];

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
		std::sort(a, a+n);
		std::sort(b, b+n);
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << ' ';
 		}	
 		std::cout << '\n';
 		for (int i = 0; i < n; i++) {
			std::cout << b[i] << ' ';
 		}	
 		std::cout << '\n';
	}
	
}