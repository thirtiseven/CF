#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int T, n, a[maxn], num[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		std::fill(num, num+n+1, 0);
		int minn = 100000000;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			if (num[a[i]] != 0) {
				minn = std::min(i-num[a[i]]+1, minn);
			}
			num[a[i]] = i;
		}
		if (minn == 100000000) {
			minn = -1;
		}	
		std::cout << minn << '\n';
	}
}