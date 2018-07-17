#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int main(int argc, char *argv[]) {  
	long long n, d[maxn];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> d[i];
	}
	long long sum1 = 0, sum3 = 0;
	int label = n;
	long long ans = 0;
	for (int i = 0; i < label; i++) {
//		if (sum1 == sum3 && i < label) {
//			ans = sum1;
//		}
		sum1 += d[i];
		while(sum1 > sum3) {
			label--;
			if (label <= i) {
				goto outt;
			}
			sum3 += d[label];
		}
		if (sum1 == sum3 && i < label) {
			ans = sum1;
		}
	}
	outt:;
	std::cout << ans;
}