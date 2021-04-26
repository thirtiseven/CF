#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;
using ll = long long;

ll t, A, B, n, a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> A >> B >> n;
		ll minn = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			minn = std::max(a[i], minn);
		}
		for (int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			B -= a[i]*(b[i]/A+int(b[i]%A>0));
		}
		if (B > -minn) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}