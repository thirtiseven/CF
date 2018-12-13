#include <iostream>
#include <algorithm>
#include <cmath>

using ll = long long;
const int maxn = 1e7+9;
const int maxm = 1e6+7;

bool flag[maxn]; 
int primes[maxm], totPrimes;

void euler_sieve(int n) {
	totPrimes = 0;
	std::fill(flag, flag+maxm, 0);
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			primes[totPrimes++] = i;
		}
		for (int j = 0; i * primes[j] <= n; j++) {
			flag[i * primes[j]] = true;
			if (i % primes[j] == 0)
			break;
		}
	}
}

int main(int argc, char *argv[]) {
	euler_sieve(maxn-3);
	int T;
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		ll n;
		std::cin >> n;
		ll t = n;
		ll ans = 1;
		for (int i = 0; i < totPrimes && primes[i] * primes[i] <= n; i++) {
			ll cnt = 0;
			while (t % primes[i] == 0) {
				cnt++;
				t /= primes[i];
			}
			ans *= (2 * cnt + 1);
		}
		if (t > 1) {
			ans *= 3;
		}
		ans = ans / 2 + 1LL;
		std::cout << "Case " << CAS << ": " << ans << std::endl;
	}
	return 0;
}