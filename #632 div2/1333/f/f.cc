#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

const int maxn = 5e5+7;
int flag[maxn], primes[maxn], totPrimes;
int n, vis[maxn];
std::set<int> x;

void euler_sieve(int n) {
	totPrimes = 0;
	memset(flag, 0, sizeof(flag));
	flag[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			primes[totPrimes++] = i;
		}
		for (int j = 0; i * primes[j] <= n; j++) {
			flag[i * primes[j]] = 1;
			if (i % primes[j] == 0)
			break;
		}
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	euler_sieve(n);
	std::fill(vis, vis+n+1, 0);
	for (int i = 0; i < totPrimes; i++) {
		std::cout << "1 ";
		vis[primes[i]] = 1;
		x.insert(primes[i]);
	}
	int x = 0;
	for (int i = 2; i <= n; i++) {
		while (x.begin() < i) {
			x.erase(x.begin());
		}
		for (auto j: x) {
			if (j*i <= n) {
				if (!vis[j*i]) {
					vis[j*i] = 1;
					std::cout << i << ' ';
				}
			} else {
				break;
			}
		}
	}
//	std::cout << '\n' << num << '\n';
}