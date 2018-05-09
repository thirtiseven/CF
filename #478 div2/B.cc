#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	long long a[16];
	for (int i = 0; i < 14; i++) {
		std::cin >> a[i];
	}
	long long ans = 0, tot = 0;
	for (int i = 0; i < 14; i++) {
		tot = 0;
		long long b[16];
		long long all = a[i]/14;
		for (int j = 0; j < 14; j++) {
			b[j] = a[j]+all;
		}
		b[i] = all;
		long long re = a[i]%14;
		for (int j = 1; j <= re; j++) {
			b[(i+j)%14]++;
		}
		for (int j = 0; j < 14; j++) {
			if (b[j] %2 == 0) {
				tot += b[j];
			}
		}
		ans = std::max(ans, tot);
	}
	std::cout << ans;
}