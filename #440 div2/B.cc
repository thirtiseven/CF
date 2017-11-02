#include <iostream>
#include <algorithm>
#include <cmath>

#define maxn 100009
#define inf 1e9+10

int main(int argc, char *argv[]) {  
	long long n, k, ans = -inf, ans2 = inf;
	std::cin >> n >> k;
	long long a[maxn];
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	if(k == 1) {
		std::sort(a,a+n);
		std::cout << a[0];
	} else if(k == 2) {
		std::cout << std::max(a[0], a[n-1]);
	} else {
		std::sort(a,a+n);
		std::cout << a[n-1];
	}
	return 0;
}