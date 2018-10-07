#include <iostream>
#include <algorithm>

const int maxn = 1234;

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int a[maxn];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	int ans = 0;
	std::cout << a[n-1]-a[0]-n+1 << '\n';
}