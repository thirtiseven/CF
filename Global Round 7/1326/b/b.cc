#include <iostream>
#include <algorithm>

const int maxn = 200000+7;

int n, a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		a[i] = b[i] + maxx;
		maxx = std::max(a[i], maxx);
	}
	for (int i = 1; i <= n; i++) {
		std::cout << a[i] << " \n"[i==n];
	}
}