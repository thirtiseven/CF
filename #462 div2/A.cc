#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	long long n, m;
	std::cin >> n >> m;
	long long a[100], b[100];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	std::sort(a, a+n);
	std::sort(b, b+m);
	std::cout << std::min(std::max(a[0]*b[0], a[n-2]*b[m-1]), std::max(a[1]*b[0], a[n-1]*b[m-1]));
}