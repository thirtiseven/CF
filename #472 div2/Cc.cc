#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>

const long long maxn = 1e5+9;

int main(int argc, char *argv[]) {  
	long long n;
	long long e[maxn];
	long long u;
	memset (e, 0, sizeof(e));
	std::cin >> n >> u;
	for (int i = 0; i < n; i++) {
		std::cin >> e[i];
	}
	long double maxx = 0;
	for (int i = 0; i < n-2; i++) {
		int pos = std::lower_bound(e, e+n, e[i]+u) - e;
		if (e[pos] - e[i] > u) {
			pos--;
		}
		long long x = e[pos];
		if (x == 0) x = e[n-1];
		if (pos <= i+1) continue;
		maxx = std::max(maxx, (long double)(x-e[i+1])/(long double)(x-e[i]));
//		std::cout << i << " " << x << " " << pos << " ";
//		std::cout << maxx << std::endl;
	}
	if (maxx) {
		std::cout << std::fixed << std::setprecision(12) << maxx << std::endl;
	} else {
		std::cout << "-1\n";
	}

}