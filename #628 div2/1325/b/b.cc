#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int T;
int n, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	int size = std::unique(a, a+n) - a;
	std::cout << size << '\n';		
	}
}