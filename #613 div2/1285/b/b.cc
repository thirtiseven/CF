#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;
using ll = long long;

ll T, n, a[maxn];
ll sum, maxx, cur;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		sum = 0;
		cur = 0;
		maxx = -10000000000000;
		bool yes = 0;
		std::cin >> n;
		int xx = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			sum += a[i];
			cur += a[i];
			if (cur > maxx) {
				maxx = cur;
				xx = i;
			}
			if (cur <= 0) {
				yes = 1;
				cur = 0;
			}
		}
		if (xx == n-1 && yes == 0) {
			maxx -= std::min(a[0], a[n-1]);
		}
		if (sum > maxx) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
	
}