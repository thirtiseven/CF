#include <iostream>
#include <algorithm>
#include <cstring>

#define ll long long
#define maxn 100010

int main(int argc, char *argv[]) {  
	ll n, k, m, a[maxn], num[maxn];
	memset(num, 0, sizeof(num));
	std::cin >> n >> k >> m;
	for(ll i = 0; i < n; i++) {
		std::cin >> a[i];
		num[a[i] % m]++;
	}
	ll thatnum = -1;
	for(ll i = 0; i < maxn; i++) {
		if(num[i] >= k) {
			thatnum = i;
			break;
		}
	}
	if(thatnum == -1) {
		std::cout << "No\n";
	} else {
		std::cout << "Yes\n";
		for(ll i = 0; i < n; i++) {
			if(a[i]%m == thatnum) {
				std::cout << a[i] << " ";
				k--;
				if(k <= 0) {
					break;
				}
			}
		}
		std::cout << '\n';
	}
	return 0;
}