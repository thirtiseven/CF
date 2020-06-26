#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 2e5+7;

ll mod(ll n, ll k) {
	return (k+(n)%k)%k;
}

ll a[maxn], b[2*maxn], n, T;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			b[i] = i+mod(a[i], n);
		}
		for (int i = 0; i < n; i++) {
			b[i+n] = i+n+mod(a[i], n);
		}
		std::sort(b, b+n*2);
		bool yes = 1;
		for (int i = 0; i < n*2-1; i++) {
			if (b[i] == b[i+1]) {
				yes = 0;
				break;
 			}
		}
//		for (int i = 0; i < 2*n; i++) {
//			std::cout << b[i] << " \n"[i==2*n-1];
//		}
		std::cout << (yes?"YES\n":"NO\n");
	}
}