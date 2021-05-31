#include <iostream>
#include <algorithm>

using ll = long long;

const int maxn = 1e6+7;

const ll mod =  998244353;

ll fac[maxn];//用来存储数字i的因数个数
ll cnt[maxn];//用来存储数字i最小素因子的幂次
ll prime[maxn] = {0};

void init(ll n) {
	fac[0] = 1;
	fac[1] = 1;
	for (ll i = 2; i <= n; i++) {
		if (!prime[i]) {//如果是素数我们让它的因数个数为2
			prime[++prime[0]] = i;
			fac[i] = 2;
			cnt[i] = 1;//素数的最小素因数是它自己;
		}
		for (ll j = 1; j <= prime[0]; j++) {
			if (prime[j] * i > n) break;
			prime[prime[j] * i] = 1;//利用素因数标记;
			if (i % prime[j] == 0) {
				fac[i * prime[j]] = fac[i] /(cnt[i] +1) * (cnt[i] + 2);//这里我们用fac[i]的因子个数除它最小素因子的幂次+1,在乘上它[(最小幂次+1)+1]
				cnt[i * prime[j]] = cnt[i] + 1;//这个数的最小幂次更新为合因子的最小次幂加1;
				break;
			}
			else { // 当这个素是两个互素的数标记时
				fac[i * prime[j]] = fac[i] * fac[prime[j]];
				cnt[i * prime[j]] = 1;
			}
		}
	}
}

ll twopow[maxn];

ll n;

int main(int argc, char *argv[]) {
	std::cin >> n;
	twopow[0] = 1;
	twopow[1] = 1;
	init(n);
	for (ll i = 2; i <= n; i++) {
		twopow[i] = twopow[i-1] * 2 % mod;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ans += twopow[i] * fac[n-i];
		ans %= mod;
	}
//	for (int i = 0; i <= n; i++) {
//		std::cout << twopow[i] << " \n"[i==n];
//	}
//	for (int i = 0; i <= n; i++) {
//		std::cout << fac[i] << " \n"[i==n];
//	}
	std::cout << ans << '\n';
}