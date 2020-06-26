#include <iostream>

using ll = long long;

ll t, d, m, a[100], p[100], x[100];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> d >> m;
		ll temp = 1, now = d, cnt = 0;
		while (now) {
			a[cnt] = std::min(now, temp);
			now -= a[cnt];
			temp *= 2;
			cnt++;
		}
//		for (int i = 0; i < cnt; i++) {
//			std::cout << a[i] << " \n"[i==cnt-1];
//		}
		x[0] = p[0] = 1;
		for (int i = 1; i < cnt; i++) {
			x[i] = a[i] + a[i] * p[i-1];
			x[i] %= m;
			p[i] = p[i-1] + x[i];
			p[i] %= m;
		}
//		std::cout << p[cnt-1] << '\n';
		ll ans = p[cnt-1]%m;
		std::cout << ans << '\n';
	}
}