#include <iostream>
#include <algorithm>

const int maxn = 1234;

int main(int argc, char *argv[]) {  
	int n, a[maxn];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	std::cout << a[(n-1)/2] << '\n';
}