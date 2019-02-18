#include <iostream>
#include <cmath>

const int maxn = 1e7+10;

bool prime_or_not[maxn];

using ll = unsigned long long;

int main(int argc, char *argv[]) {  
	for (ll i = 2; i * i <= maxn; i++) {
		if (!prime_or_not[i]) {
	    	for (ll j = i * i; j <= maxn; j = j+i) {
				prime_or_not[j] = 1;
			}
		}
	}
	ll n, b;
	std::cin >> n >> b;
	ll ans = 0;
	ll maxx = 1LL;
	for (ll i = 2LL; i <= (ll)sqrt(b)+1LL; i++) {
		if (b%i==0) {
			if (!prime_or_not[i]) {
				maxx = std::max(maxx, i);
			}
			if (b/i < maxn && !prime_or_not[b/i]) {
				maxx = std::max(maxx, b/i);
			}
		}
	}
	if (maxx == 1LL) {
		maxx = b;
	}
	ll divv = 0;
	while (b % maxx == 0) {
		divv++;
		b /= maxx;
	}
	std::cerr << maxx << " " << divv << '\n';
	ll now = maxx*divv;
	while (now <= n) {
		ans += (n/now);
		if (double(now) * double(maxx) < double (n+1)) {
			now *= maxx;
		} else {break;}
	}
	std::cout << ans;
}


