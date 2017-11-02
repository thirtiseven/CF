#include <iostream>
#include <algorithm>
#define maxn 510

int main(int argc, char *argv[]) {  
	long long n, k, a[maxn], maxx = -1;
	std::cin >> n >> k;
	for(long long i = 0; i < n; i++) {
		std::cin >> a[i];
		maxx = std::max(maxx, a[i]);
	}
	if(k >= n) {
		std::cout << maxx << std::endl;
		return 0;
	}
	long long ans = 0;
	bool flag = 1;
	for(long long i = 0; i < n; i++) {
		flag = 1;
		int up = k;
		if(a[(i+n-1)%n] < a[i]) up--;
		for(long long j = 1; j <= up; j++) {
			if(a[(i+j)%n] > a[i]) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			ans = a[i];
			break;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}