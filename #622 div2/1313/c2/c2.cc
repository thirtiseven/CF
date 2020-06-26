#include <iostream>
#include <algorithm>

const int maxn = 500003;
const int inf = 2e9+7;

using ll = long long;

ll n;
ll m[maxn], ins[maxn], des[maxn];
ll arrowr[maxn], arrowl[maxn];
ll pre[maxn], shf[maxn];
ll ans[maxn], maxx[maxn];
ll pos, cur = 0;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	pre[0] = shf[n+1] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> m[i];
		pre[i] = pre[i-1] + m[i];
	}
	for (int i = n; i >= 1; i--) {
		shf[i] = shf[i+1] + m[i];
	}
	m[0] = m[n+1] = -inf;
	for (int i = n; i >= 1; i--) {
		if (m[i+1] < m[i]) {
			arrowr[i] = i+1;
		} else {
			arrowr[i] = arrowr[i+1];
			while (m[arrowr[i]] >= m[i]) {
				arrowr[i] = arrowr[arrowr[i]];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (m[i-1] < m[i]) {
			arrowl[i] = i-1;
		} else {
			arrowl[i] = arrowl[i-1];
			while (m[arrowl[i]] >= m[i]) {
				arrowl[i] = arrowl[arrowl[i]];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ins[i] = ins[arrowl[i]] + (i-arrowl[i])*m[i];
	}
	for (int i = n; i >= 1; i--) {
		des[i] = des[arrowr[i]] + (arrowr[i]-i)*m[i];
	}
	for (int i = 1; i <= n; i++) {
		maxx[i] = ins[i] + des[i] - m[i];
	}
	for (int i = 1; i <= n; i++) {
		if (maxx[i] > cur) {
			cur = maxx[i];
			pos = i;
		}
	}
	cur = m[pos];
	for (int i = pos; i >= 1; i--) {
		ans[i] = std::min(m[i], cur);
		cur = ans[i];
	}
	cur = m[pos];
	for (int i = pos; i <= n; i++) {
		ans[i] = std::min(m[i], cur);
		cur = ans[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << ' ';
	}
}