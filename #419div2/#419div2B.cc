#include <iostream>
#include <cstring>
#define ll long long

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	ll n, k, q;
	ll c[200010];
	memset(c, 0, sizeof(c));
	ll l, r;
	std::cin >> n >> k >> q;
	for(int i = 0; i < n; i++) {
		std::cin >> l >> r;
		c[l]++;
		c[r+1]--; 
	}
	for(int i = 1; i <= 200000; i++) {
		c[i] += c[i-1];
	}
	for(int i = 1; i <= 200000; i++) {
		if(c[i] >= k) {
			c[i] = 1;
		} else {
			c[i] = 0;
		}
		c[i] += c[i-1];
	}
	ll a, b;
	for(int i = 0; i < q; i++) {
		std::cin >> a >> b;
		std::cout << c[b] - c[a-1] << "\n";
	}
	return 0;
}