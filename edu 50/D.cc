#include <iostream>

const int maxn = 3e5+7;
using ll = long long;
ll n, m, a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	ll ans = 0;
	ll nowa = 0, nowb = 0, suma = 0, sumb = 0;
	while (nowa < n || nowb < m) {
		if (suma != 0 && suma == sumb) {
			suma = sumb = 0;
			ans++;
		}
		if (suma < sumb) {
			if (nowa < n) {
				suma += a[nowa];
				nowa++;	
			} else {
				break;
			}
		} else if (suma > sumb) {
			if (nowb < m) {
				sumb += b[nowb];
				nowb++;
			} else {
				break;
			}
		} else {
			if (nowb < m) {
				sumb += b[nowb];
				nowb++;
			} else {
				break;
			}
			if (nowa < n) {
				suma += a[nowa];
				nowa++;	
			} else {
				break;
			}
		}
	}
	if (suma == sumb && suma != 0) {
		ans++;
		suma = sumb = 0;
	}
	if (suma || sumb || nowa != n || nowb != m) {
		std::cout << "-1\n";
	} else {
		std::cout << ans << '\n';
	}
}