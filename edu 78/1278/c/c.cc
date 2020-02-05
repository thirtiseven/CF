#include <iostream>
#include <algorithm>

const int maxn = 1e5+4;

int T;
int n;
int left[maxn], right[maxn], numl[maxn], numr[maxn];
int occ[maxn*2];
int suml[3], sumr[3];

void init() {
	suml[1] = suml[2] = sumr[1] = sumr[2] = 0;
	std::fill(occ+maxn-n-1, occ+maxn+n+1, 10000000);
}

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		init();
		for (int i = 0; i < n; i++) {
			std::cin >> left[n-i];
			suml[left[n-i]]++;
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> right[i];
			sumr[right[i]]++;
		}
		numl[0] = suml[1]-suml[2];
		for (int i = 1; i <= n; i++) {
			if (left[i] == 1) {
				numl[i] = numl[i-1] - 1;
			} else {
				numl[i] = numl[i-1] + 1;
			}
		}
		numr[0] = sumr[1]-sumr[2];
		for (int i = 1; i <= n; i++) {
			if (right[i] == 1) {
				numr[i] = numr[i-1] - 1;
			} else {
				numr[i] = numr[i-1] + 1;
			}
		}
		for (int i = n; i >= 0; i--) {
			occ[numr[i]+maxn] = i;
		}
		int ans = n*2;
		for (int i = 0; i <= n; i++) {
			if (occ[maxn-numl[i]] <= n) {
				ans = std::min(ans, occ[maxn-numl[i]]+i);
			}
		}
		std::cout << ans << '\n';
	}
}