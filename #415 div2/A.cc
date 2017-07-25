#include <iostream>
#define maxn 110

int main(int argc, char *argv[]) {  
	int n, k, ans, a[maxn], sum = 0;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	ans = 2 * (n * k - sum) - n;
	if(ans < 0) {
		ans = 0;
	}
	std::cout << ans << std::endl;
	return 0;
}