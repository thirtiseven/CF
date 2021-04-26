#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
using ll = unsigned int;

ll n, a[maxn];
ll bit[maxn][40], occ[maxn][40];

int BitLength(unsigned int n) {     // pow of 2, 2^0 - 2 ^31     
	ll powof2[32] =     {                  1,           2,           4,           8,         16,          32,                 64,         128,         256,         512,       1024,        2048,               4096,        8192,       16384,       32768,      65536,      131072,             262144,      524288,     1048576,     2097152,    4194304,     8388608,           16777216,    33554432,    67108864,   134217728,  268435456,   536870912,         1073741824,  2147483648     } ;     int left = 0 ;     
	int right = 31 ;     
	while (left <= right) {         
		int mid = (left + right) / 2 ;         
		if (powof2[mid] <= n) {             
			if (powof2[mid + 1] > n)                 
				return mid + 1; // got it!             
			else // powof2[mid] < n, search right part                
				left = mid + 1 ;         
		} else // powof2[mid] > n, search left part             
			right = mid - 1 ;     
	}
	return -1;
}

void gao(ll a, int b) {
	int cnt = 0;
	while (a) {
		bit[b][cnt] = a%2;
		cnt++;
		a/=2;
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		gao(a[i], i);
	}
	for (int i = 0; i < 32; i++) {
		occ[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 32; j++) {
			if (bit[i][j] == 1) {
				occ[i][j] = i;
			} else {
				occ[i][j] = occ[i-1][j];
			}
		}
	}
	ll ans = 1000000;
	for (int i = 2; i <= n-1; i++) {
		bool anyone = 1, ok = 1;
		ll temp1 = maxn, temp2 = 0;
		ll upp = BitLength(a[i+1]);
		for (int j = 0; j < upp; j++) {
			if (bit[i+1][j] == 0 && bit[i][j] == 1) {
				anyone = 0;
			} else if (bit[i+1][j] == 0 && bit[i][j] == 0) {
				if (occ[i][j] == 0) {
					ok = 0;
					break;
				}
				temp1 = std::min(temp1, i-occ[i][j]);
			} else if (bit[i+1][j] == 1 && bit[i][j] == 0) {
				if (occ[i][j] == 0) {
					ok = 0;
					break;
				}
				temp2 = std::max(temp2, i-occ[i][j]);
			}
		}
		if (ok) {
			if (anyone) {
				ans = std::min(ans, std::max(temp1, temp2));
			} else {
				ans = std::min(ans, temp2);
			}
		}
	}
	if (ans >= maxn) {
		std::cout << "-1\n";
		exit(0);
	}
	std::cout << ans << '\n';
}