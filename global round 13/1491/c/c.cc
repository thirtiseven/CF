#include <iostream>
#include <algorithm>
#include <cassert>
#include <fstream>

using ll = long long;
const int maxn = 5007;
ll t, n, S[maxn], ans[maxn];
ll res;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		res = 0;
		std::cin >> n;
		for (ll i = 0; i < n; i++) {
			std::cin >> S[i];
			ans[i] = 0;
		}
		for (ll i = 0; i < n; i++) {
			ll temp = ans[i];
			if (temp < S[i]-1){
				res += S[i] - 1 - temp;
				temp += S[i] - 1 - temp;
			}
			ans[i+1] += temp - S[i] + 1;
			if (i+2 < n) {
				for (int j = i+2; j < std::min(n,i+S[i]+1); j++) {
					ans[j]++;
				}
			}
 		}
		std::cout << res << '\n';
	}
}