#include <iostream>
#include <tuple>
#include <algorithm>

int n, m, q;

struct customer{
	int a, b, c;	
}cus[102];

bool cmp(customer x, customer y) {
	return x.a < y.a;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> q;
	while (q--) {
		std::cin >> n >> m;
		cus[0].a = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> cus[i].a >> cus[i].b >> cus[i].c;
		}
		std::sort(cus+1, cus+n+1, cmp);
		int upper = m, lower = m;
		bool yes = 1;
		for (int i = 1; i <= n; i++) {
			upper += (cus[i].a-cus[i-1].a);
			lower -= (cus[i].a-cus[i-1].a);
			if (upper >= cus[i].b && lower <= cus[i].c) {
				upper = std::min(upper, cus[i].c);
				lower = std::max(lower, cus[i].b);
			} else {
				yes = 0;
				break;
			}
//			std::cout << lower << ' ' << upper << '\n';
		}
		std::cout << (yes?"YES\n":"NO\n");
	}
}