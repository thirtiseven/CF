#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 1e6+7;

ll A, B, C, D;
ll pre[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> A >> B >> C >> D;
	std::fill(pre, pre+maxn, 0);
	for (int i = A; i <= B; i++) {
		pre[i+B]++;
		pre[i+C+1]--;
	}
	for (int i = 1; i < maxn; i++) {
		pre[i] += pre[i-1];
	}
	for (int i = 1; i < maxn; i++) {
		pre[i] += pre[i-1];
	}
	ll ans = 0;
	for (int i = C; i <= D; i++) {
		ans += pre[maxn-1] - pre[i];
	}
	std::cout << ans << '\n';
}