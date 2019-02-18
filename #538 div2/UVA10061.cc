#include <cstdio>
#include <cmath>

using ll = long long;

ll count_zero(ll n,ll b) {
	ll cnt1,cnt2;
	ll maxprime;
	for(ll i = 2; i <= b; i++) {
		cnt1 = 0;
		while(b % i == 0) {
			maxprime = i;
			cnt1++;
			b /= i;
		}
	}
	cnt2 = 0;
	for (ll i = maxprime; i <= n; i *= maxprime) {
		cnt2 += (n/i)/cnt1;
	}
	return cnt2;
}

int main() {
	ll n, b;
	scanf("%lld%lld",&n,&b);
	ll zero = count_zero(n,b);
	printf("%lld\n",zero);
	return 0;
}

20833333333333332
20833333333333320

83333333333333328
83333333333333324

