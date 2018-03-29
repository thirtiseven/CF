#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

const long long maxn = 1e5+9;

int main(int argc, char *argv[]) {  
	long long n;
	long long	e[maxn];
	long long u;
	std::cin >> n >> u;
	for (int i = 0; i < n; i++) {
		std::cin >> e[i];
	}
	long double maxx = 0;
	long long l = 0, r = 2;
	long long now = e[2] - e[0];
	if (now <= u && r - l >= 2) {
//		std::cout << l << " " << r << " " << now << "YEES" << '\n';
		maxx = std::max(maxx, (long double)(e[r]-e[l+1])/(long double)(e[r]-e[l]));
	}
	while (r < n) {
		if (now > u) {
			l++;
			now = e[r]-e[l];
		} else if (now < u){
			r++;
			now = e[r]-e[l];
		} else {
			l++, r++;
			now = e[r]-e[l];
		}
		if (r < n && now <= u && r - l >= 2) {
//			std::cout << l << " " << r << " " << now << "YEES" << '\n';
			maxx = std::max(maxx, (long double)(e[r]-e[l+1])/(long double)(e[r]-e[l]));
		}
//		std::cout << l << " " << r << " " << now << '\n';
	}
	if (maxx) {
		std::cout << std::fixed << std::setprecision(12) << maxx << std::endl;
	} else {
		std::cout << "-1\n";
	}
}